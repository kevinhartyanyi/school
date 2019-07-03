using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Radar
{
    class Varos
    {
        double xKoordinata;
        double yKoordinata;
        double varosSugara;

        public Varos(double xKoordinata, double yKoordinata, double varosSugara)
        {
            this.xKoordinata = xKoordinata;
            this.yKoordinata = yKoordinata;
            this.varosSugara = varosSugara;
        }

        public double XKoordinata
        {
            get { return xKoordinata; }
            set { xKoordinata = value; }
        }

        public double YKoordinata
        {
            get { return yKoordinata; }
            set { yKoordinata = value; }
        }

        public double VarosSugara
        {
            get { return varosSugara; }
            set { varosSugara = value; }
        }
    }
}
