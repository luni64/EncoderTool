using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Model
{
    class EncDecoder
    {
        public int value { get; private set; } = 0;

        uint state;

        public bool update(uint phaseA, uint phaseB) // http://www.buxtronix.net/2011/10/rotary-encoders-done-properly.html
        {
            state = stateMachineFull[state, phaseA << 1 | phaseB];    // get next state depending on the inputs
            uint direction = state & 0xF0;                      // set if we need to count up / down or got an error
            state &= 0x0F;                                        // remove the direction info from state

            if (direction == UP)
            {
                value++;
            }

            if (direction == DOWN)
            {
                value--;
            }

            if (direction == ERR)
            {
               
            }

            return false;
        }




        const uint start = 0x00;
        const uint cw_A = 0x01;
        const uint cw_B = 0x02;
        const uint cw_C = 0x03;
        const uint ccw_A = 0x04;
        const uint ccw_B = 0x05;
        const uint ccw_C = 0x06;

        const uint UP = 0x10;
        const uint DOWN = 0x20;
        const uint ERR = 0x30;


        private uint[,] stateMachineFull = new uint[7, 4]
        {
        //            00          01          10          11
        /*0 start*/ {start,      cw_A,      ccw_A,     start|ERR},
        /*1 cw_A*/  {start,      cw_A,      cw_A|ERR,  cw_B     },
        /*2 cw_B*/  {cw_B|ERR,   cw_A,      cw_C,      cw_B     },
        /*3 cw_C*/  {start|UP,   cw_C|ERR,  cw_C,      cw_B     },

        /*4 ccwA*/  {start,      ccw_A|ERR, ccw_A,     ccw_B    },
        /*5 ccwB*/  {ccw_B|ERR,  ccw_C,     ccw_A,     ccw_B    },
        /*6 ccwC*/  {start|DOWN, ccw_C,     ccw_C|ERR, ccw_B    },
        };

    }
}
//const uint8_t EncoderBase::stateMachineHalf[7][4]
//{
//    //            00          01          10          11
//    /*0 start*/ {start,      cw_A,      ccw_A,     start|ERR},
//    /*1 cw_A*/  {start,      cw_A,      cw_A|ERR,  cw_B     },
//    /*2 cw_B*/  {cw_B|ERR,   cw_A,      cw_C,      cw_B     },
//    /*3 cw_C*/  {start|UP,   cw_C|ERR,  cw_C,      cw_B     },

//    /*4 ccwA*/  {start,      ccw_A|ERR, ccw_A,     ccw_B    },
//    /*5 ccwB*/  {ccw_B|ERR,  ccw_C,     ccw_A,     ccw_B    },
//    /*6 ccwC*/  {start|DOWN, ccw_C,     ccw_C|ERR, ccw_B    },
//};
