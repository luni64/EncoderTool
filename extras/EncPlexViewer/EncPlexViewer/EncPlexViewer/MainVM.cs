using OxyPlot;
using OxyPlot.Axes;
using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using ViewModel;
using System.Linq;
using OxyPlot.Series;
using System.Windows;
using Model;

namespace ViewModel
{

    public class datum
    {
        public double time;
        public uint A, B;
        public int value;
    }


    public class MainVM : BaseViewModel
    {
        EncDecoder decoder;

        public string Message
        {
            get => _message;
            set => SetProperty(ref _message, value);
        }
        string _message;
        
        List<datum> data = new List<datum>();

        public RelayCommand cmdImportGood { get; private set; }
        void doImportGood(object o)
        {
            if (Clipboard.ContainsText())
            {
                data.Clear();
                try
                {                  
                    var text = Clipboard.GetText();
                    var lines = text.Split(new char[] { '\n', '\r' }, StringSplitOptions.RemoveEmptyEntries).ToList();
                    foreach (var line in lines.Skip(0))
                    {
                        var cols = line.Split(',');
                      
                        data.Add(new datum()
                        {
                            time = Convert.ToDouble(cols[0]),
                            A = Convert.ToUInt32(cols[1]),
                            B = Convert.ToUInt32(cols[2]),
                        });
                    }
                    Message = "";
                }
                catch
                {
                    Message = "Could not parse data";
                }

                display();
            }
        }


        public void display()
        {
            double oldA = 0, oldB = 0;

            A.Points.Clear();
            B.Points.Clear();

            foreach (var datum in data)
            {
                A.Points.Add(new DataPoint(datum.time, oldA));
                A.Points.Add(new DataPoint(datum.time, datum.A));
                B.Points.Add(new DataPoint(datum.time, oldB+1.2));
                B.Points.Add(new DataPoint(datum.time, datum.B + 1.2));
                oldA = datum.A;
                oldB = datum.B;
            }
            
            pm.InvalidatePlot(true);
        }


        public RelayCommand cmdImportBad { get; private set; }
        void doImportBad(object o)
        {

            pm.InvalidatePlot(true);
        }

        public RelayCommand cmdNormalize { get; private set; }
        void doNormalize(object o)
        {


            pm.InvalidatePlot(true);
        }

        List<List<(double x, double y)>> goodData = new List<List<(double x, double y)>>();
        List<List<(double x, double y)>> badData = new List<List<(double x, double y)>>();


        public PlotModel pm { get; } = new OxyPlot.PlotModel();

        public MainVM()
        {
            cmdImportGood = new RelayCommand(doImportGood);
            cmdImportBad = new RelayCommand(doImportBad);
            cmdNormalize = new RelayCommand(doNormalize);
            setupPlot();
        }


        LineSeries A; 
        LineSeries B;

        private void setupPlot()
        {
            A = new LineSeries()
            {
                StrokeThickness = 1,
                Color = OxyColors.Blue,
                CanTrackerInterpolatePoints = false,
            };
            B = new LineSeries()
            {
                StrokeThickness = 0.7,
                Color = OxyColors.Red,
                CanTrackerInterpolatePoints = false,
        };

            var xAxis = new LinearAxis
            {
                //Minimum = -0.8,
                //Maximum = 0.8,
                Position = AxisPosition.Bottom,
                MajorGridlineStyle = LineStyle.Solid,
                MinorGridlineStyle = LineStyle.Solid,
                MinorGridlineThickness = 0.5,
                MinorGridlineColor = OxyColors.LightGray,
                MajorGridlineThickness = 1,
                MajorGridlineColor = OxyColors.Gray,
                

                StringFormat = "F4",
            };


            var yAxis = new LinearAxis
            {              
                MaximumPadding = 0.1,
                MinimumPadding = 0.1,
                Position = AxisPosition.Left,
                IsZoomEnabled = false,
                IsPanEnabled = false,
                IsAxisVisible = false,
                
            };
           
            pm.Axes.Add(xAxis);
            pm.Axes.Add(yAxis);
            pm.Series.Add(A);
            pm.Series.Add(B);
            pm.IsLegendVisible = false;
        }
    }
}
