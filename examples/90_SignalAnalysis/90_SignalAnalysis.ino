constexpr size_t bufSize = 10;

struct
{
    unsigned cycles;
    unsigned phaseA;
    unsigned phaseB;
} data[bufSize];


void setup()
{
    while (!Serial) {}
    Serial.println("asdf");

    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(0, INPUT_PULLUP);
    pinMode(1, INPUT_PULLUP);

    data[0].cycles = ARM_DWT_CYCCNT;
    data[0].phaseA = digitalReadFast(0);
    data[0].phaseB = digitalReadFast(1);

    unsigned i = 0;
    while (i < bufSize)
    {
        unsigned cycles = ARM_DWT_CYCCNT;
        unsigned A = digitalReadFast(0);
        unsigned B = digitalReadFast(1);

        if (A != data[i - 1].phaseA || B != data[i - 1].phaseB)
        {
            data[i].cycles = cycles;
            data[i].phaseA = A;
            data[i].phaseB = B;
            i++;
        }
    }


    float time = 0;

    for (unsigned i = 1; i < bufSize; i++)
    {
        double dt = (data[i].cycles - data[i-1].cycles) * 1.E3 / F_CPU;
        time += dt;
        Serial.printf("%.5f,%u,%u\n", time, data[i].phaseA, data[i].phaseB);
    }
}

int olda, oldb;


void loop()
{
    // digitalWriteFast(LED_BUILTIN, !digitalReadFast(LED_BUILTIN));
    // delay(200);

    int a = digitalReadFast(0);
    int b = digitalReadFast(1);
    //int val = a & (b << 1);

    if(a != olda || b!= oldb)
    {
        Serial.printf("x: %d%d\n", a, b);
        olda = a;
        oldb = b;
    }
}
