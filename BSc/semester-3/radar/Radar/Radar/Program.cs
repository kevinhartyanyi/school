using System;
using System.IO;

namespace Radar
{
    class Program
    {
        static void Main(string[] args)
        {
            double[,] BeolvasottRadarAdatok = RadarAllomasokAdatai(FileBeolvasas());
            double[,] BeolvasottVarosAdatok = VarosokAdatai(FileBeolvasas());
            Radar[] radarAllomasok = RadarAllomasok(BeolvasottRadarAdatok);
            Repulo repulo = RepuloLetrehozas(RepuloMertHelyzetei(RepuloLehetsegesHelyzeteiKerekites(RepuloLehetsegesHelyzetei(radarAllomasok))));
            Varos[] varosok = VarosLetrehozas(BeolvasottVarosAdatok);
            VarosKimenekites(repulo, varosok);
            Console.WriteLine("A feladat eredménye mentésre került a munkakönyvtárban lévő 'adatok.ki' nevű txt file-ba!");
            Console.Write("\nA kilépéshez nyomjon meg egy billentyűt!");
            Console.ReadLine();
        }
        //Beolvassa soronként a file tartalmát, aminek elemeit feldarabolja és menti őket egy átmeneti tömbbe,
        //majd ebből a tömbből másolja át az elemeket egy mátrixba.
        static string[,] FileBeolvasas()
        {
            StreamReader sr = new StreamReader("adatok.be.txt");
            int VarosokSzama = int.Parse(sr.ReadLine());
            string[,] BeolvasottErtekek = new string[VarosokSzama+3, 4];
            for (int i = 0; i < BeolvasottErtekek.GetLength(0); i++)
            {
                string FileSora = sr.ReadLine();
                string[] FileSoranakSzetszedese = FileSora.Split(' ');
                int j = 0;
                while (j < FileSoranakSzetszedese.Length)
                {
                    BeolvasottErtekek[i, j] = FileSoranakSzetszedese[j];
                    j++;
                }
            }
            sr.Close();
            return BeolvasottErtekek;
        }

        //Külön double típusú mátrixba másolja át a radarállomásokhoz tartozó adatokat, figyelembe véve a feladatban megadott 's' karakter jelentését.
        static double[,] RadarAllomasokAdatai(string[,] Matrix)
        {
            double[,] radarAllomasok = new double[3, 4];
            for (int i = 0; i < radarAllomasok.GetLength(0); i++)
            {
                for (int j = 0; j < radarAllomasok.GetLength(1); j++)
                {
                    if (Char.IsLetter(Matrix[i,j][0]))
                    {
                        string seged = "";
                        for (int k = 1; k < Matrix[i,j].Length; k++)
                        {
                            seged = seged + Matrix[i, j][k];
                        }
                        radarAllomasok[i, j] = Math.Sqrt(double.Parse(seged));
                    }
                    else
                    {
                        radarAllomasok[i, j] = double.Parse(Matrix[i, j]);
                    }
                }
            }
            return radarAllomasok;
        }

        //Külön double típusú mátrixba másolja át a városokhoz tartozó adatokat, figyelembe véve a feladatban megadott 's' karakter jelentését.
        static double[,] VarosokAdatai(string[,] Matrix)
        {
            double[,] varosok = new double[Matrix.GetLength(0)-3, 3];
            for (int i = 0; i < varosok.GetLength(0); i++)
            {
                for (int j = 0; j < varosok.GetLength(1); j++)
                {
                    if (Char.IsLetter(Matrix[i+3, j][0]))
                    {
                        string seged = "";
                        for (int k = 1; k < Matrix[i+3, j].Length; k++)
                        {
                            seged = seged + Matrix[i+3, j][k];
                        }
                        varosok[i, j] = Math.Sqrt(double.Parse(seged));
                    }
                    else
                    {
                        varosok[i, j] = double.Parse(Matrix[i+3, j]);
                    }
                }
            }
            return varosok;
        }

        //Példányosítja a radarállomásokat
        //Negatív értékű távolság esetén a program leáll hibaüzenettel.
        static Radar[] RadarAllomasok(double[,] RadarAdatok)
        {
            Radar[] radarAllomas = new Radar[3];
            for (int i = 0; i < RadarAdatok.GetLength(0); i++)
            {
                if ((RadarAdatok[i, 2] < 0) || (double.IsNaN(RadarAdatok[i, 2])) || (RadarAdatok[i, 3] < 0) || (double.IsNaN(RadarAdatok[i, 3])))
                {
                    int seged = i + 1;
                    Console.WriteLine("Hiba! A " + seged + ". radar által mért távolság egy negatív szám!");
                    Console.Write("\nA kilépéshez nyomjon meg egy billentyűt!");
                    Console.ReadLine();
                    Environment.Exit(0);
                }
                else
                {
                    radarAllomas[i] = new Radar(RadarAdatok[i, 0], RadarAdatok[i, 1], RadarAdatok[i, 2], RadarAdatok[i, 3]);
                }
            }
            return radarAllomas;
        }

        //Kiszámítja a radar0 & radar1; radar0 & radar2; radar1 & radar2 közös pontjait.
        static double[,] RepuloLehetsegesHelyzetei(Radar[] Tomb)

        {
            double[,] mertKoordinatak = new double[2, 12];            
            for (int j = 0; j < 2; j++)
            {
                int k = 0;
                int n = 1;
                for (int i = 0; i < 12; i++)
                {
                    if (i == 8)
                    {
                        ++k;
                    }
                    else if (i == 4)
                    {
                        ++n;
                    }
                    if (j == 0)
                    {
                        mertKoordinatak[j,  i] = RepuloLehetsegesX1Koordinataja(Tomb[k].Xkoordinata, Tomb[k].Ykoordinata, Tomb[n].Xkoordinata, Tomb[n].Ykoordinata, Tomb[k].Tavolsag1, Tomb[n].Tavolsag1);
                    }
                    else
                    {
                        mertKoordinatak[j,  i] = RepuloLehetsegesX1Koordinataja(Tomb[k].Xkoordinata, Tomb[k].Ykoordinata, Tomb[n].Xkoordinata, Tomb[n].Ykoordinata, Tomb[k].Tavolsag1, Tomb[n].Tavolsag2);
                    }
                    
                }
            }
            

            
            mertKoordinatak[0,  0] = RepuloLehetsegesX1Koordinataja(Tomb[0].Xkoordinata, Tomb[0].Ykoordinata, Tomb[1].Xkoordinata, Tomb[1].Ykoordinata, Tomb[0].Tavolsag1, Tomb[1].Tavolsag1);
            mertKoordinatak[0,  1] = RepuloLehetsegesY1Koordinataja(Tomb[0].Xkoordinata, Tomb[0].Ykoordinata, Tomb[1].Xkoordinata, Tomb[1].Ykoordinata, Tomb[0].Tavolsag1, Tomb[1].Tavolsag1);
            mertKoordinatak[0,  2] = RepuloLehetsegesX2Koordinataja(Tomb[0].Xkoordinata, Tomb[0].Ykoordinata, Tomb[1].Xkoordinata, Tomb[1].Ykoordinata, Tomb[0].Tavolsag1, Tomb[1].Tavolsag1);
            mertKoordinatak[0,  3] = RepuloLehetsegesY2Koordinataja(Tomb[0].Xkoordinata, Tomb[0].Ykoordinata, Tomb[1].Xkoordinata, Tomb[1].Ykoordinata, Tomb[0].Tavolsag1, Tomb[1].Tavolsag1);

            mertKoordinatak[0,  4] = RepuloLehetsegesX1Koordinataja(Tomb[0].Xkoordinata, Tomb[0].Ykoordinata, Tomb[2].Xkoordinata, Tomb[2].Ykoordinata, Tomb[0].Tavolsag1, Tomb[2].Tavolsag1);
            mertKoordinatak[0,  5] = RepuloLehetsegesY1Koordinataja(Tomb[0].Xkoordinata, Tomb[0].Ykoordinata, Tomb[2].Xkoordinata, Tomb[2].Ykoordinata, Tomb[0].Tavolsag1, Tomb[2].Tavolsag1);
            mertKoordinatak[0,  6] = RepuloLehetsegesX2Koordinataja(Tomb[0].Xkoordinata, Tomb[0].Ykoordinata, Tomb[2].Xkoordinata, Tomb[2].Ykoordinata, Tomb[0].Tavolsag1, Tomb[2].Tavolsag1);
            mertKoordinatak[0,  7] = RepuloLehetsegesY2Koordinataja(Tomb[0].Xkoordinata, Tomb[0].Ykoordinata, Tomb[2].Xkoordinata, Tomb[2].Ykoordinata, Tomb[0].Tavolsag1, Tomb[2].Tavolsag1);

            mertKoordinatak[0,  8] = RepuloLehetsegesX1Koordinataja(Tomb[1].Xkoordinata, Tomb[1].Ykoordinata, Tomb[2].Xkoordinata, Tomb[2].Ykoordinata, Tomb[1].Tavolsag1, Tomb[2].Tavolsag1);
            mertKoordinatak[0,  9] = RepuloLehetsegesY1Koordinataja(Tomb[1].Xkoordinata, Tomb[1].Ykoordinata, Tomb[2].Xkoordinata, Tomb[2].Ykoordinata, Tomb[1].Tavolsag1, Tomb[2].Tavolsag1);
            mertKoordinatak[0, 10] = RepuloLehetsegesX2Koordinataja(Tomb[1].Xkoordinata, Tomb[1].Ykoordinata, Tomb[2].Xkoordinata, Tomb[2].Ykoordinata, Tomb[1].Tavolsag1, Tomb[2].Tavolsag1);
            mertKoordinatak[0, 11] = RepuloLehetsegesY2Koordinataja(Tomb[1].Xkoordinata, Tomb[1].Ykoordinata, Tomb[2].Xkoordinata, Tomb[2].Ykoordinata, Tomb[1].Tavolsag1, Tomb[2].Tavolsag1);

            mertKoordinatak[1,  0] = RepuloLehetsegesX1Koordinataja(Tomb[0].Xkoordinata, Tomb[0].Ykoordinata, Tomb[1].Xkoordinata, Tomb[1].Ykoordinata, Tomb[0].Tavolsag2, Tomb[1].Tavolsag2);
            mertKoordinatak[1,  1] = RepuloLehetsegesY1Koordinataja(Tomb[0].Xkoordinata, Tomb[0].Ykoordinata, Tomb[1].Xkoordinata, Tomb[1].Ykoordinata, Tomb[0].Tavolsag2, Tomb[1].Tavolsag2);
            mertKoordinatak[1,  2] = RepuloLehetsegesX2Koordinataja(Tomb[0].Xkoordinata, Tomb[0].Ykoordinata, Tomb[1].Xkoordinata, Tomb[1].Ykoordinata, Tomb[0].Tavolsag2, Tomb[1].Tavolsag2);
            mertKoordinatak[1,  3] = RepuloLehetsegesY2Koordinataja(Tomb[0].Xkoordinata, Tomb[0].Ykoordinata, Tomb[1].Xkoordinata, Tomb[1].Ykoordinata, Tomb[0].Tavolsag2, Tomb[1].Tavolsag2);

            mertKoordinatak[1,  4] = RepuloLehetsegesX1Koordinataja(Tomb[0].Xkoordinata, Tomb[0].Ykoordinata, Tomb[2].Xkoordinata, Tomb[2].Ykoordinata, Tomb[0].Tavolsag2, Tomb[2].Tavolsag2);
            mertKoordinatak[1,  5] = RepuloLehetsegesY1Koordinataja(Tomb[0].Xkoordinata, Tomb[0].Ykoordinata, Tomb[2].Xkoordinata, Tomb[2].Ykoordinata, Tomb[0].Tavolsag2, Tomb[2].Tavolsag2);
            mertKoordinatak[1,  6] = RepuloLehetsegesX2Koordinataja(Tomb[0].Xkoordinata, Tomb[0].Ykoordinata, Tomb[2].Xkoordinata, Tomb[2].Ykoordinata, Tomb[0].Tavolsag2, Tomb[2].Tavolsag2);
            mertKoordinatak[1,  7] = RepuloLehetsegesY2Koordinataja(Tomb[0].Xkoordinata, Tomb[0].Ykoordinata, Tomb[2].Xkoordinata, Tomb[2].Ykoordinata, Tomb[0].Tavolsag2, Tomb[2].Tavolsag2);

            mertKoordinatak[1,  8] = RepuloLehetsegesX1Koordinataja(Tomb[1].Xkoordinata, Tomb[1].Ykoordinata, Tomb[2].Xkoordinata, Tomb[2].Ykoordinata, Tomb[1].Tavolsag2, Tomb[2].Tavolsag2);
            mertKoordinatak[1,  9] = RepuloLehetsegesY1Koordinataja(Tomb[1].Xkoordinata, Tomb[1].Ykoordinata, Tomb[2].Xkoordinata, Tomb[2].Ykoordinata, Tomb[1].Tavolsag2, Tomb[2].Tavolsag2);
            mertKoordinatak[1, 10] = RepuloLehetsegesX2Koordinataja(Tomb[1].Xkoordinata, Tomb[1].Ykoordinata, Tomb[2].Xkoordinata, Tomb[2].Ykoordinata, Tomb[1].Tavolsag2, Tomb[2].Tavolsag2);
            mertKoordinatak[1, 11] = RepuloLehetsegesY2Koordinataja(Tomb[1].Xkoordinata, Tomb[1].Ykoordinata, Tomb[2].Xkoordinata, Tomb[2].Ykoordinata, Tomb[1].Tavolsag2, Tomb[2].Tavolsag2);
            return mertKoordinatak;
        }

        //Kiszámítja az első metszési pont X koordinátáját.
        static double RepuloLehetsegesX1Koordinataja(double kor1kozeppontX, double kor1kozeppontY, double kor2kozeppontX, double kor2kozeppontY, double kor1sugara, double kor2sugara)
        {
            double iranyVektorX = kor1kozeppontX - kor2kozeppontX;
            double iranyVektorY = kor1kozeppontY - kor2kozeppontY;
            double ketKorTavolsaga = Math.Sqrt(iranyVektorX * iranyVektorX + iranyVektorY * iranyVektorY);
            double a = (kor1sugara * kor1sugara - kor2sugara * kor2sugara + ketKorTavolsaga * ketKorTavolsaga) / (2 * ketKorTavolsaga);
            double h = Math.Sqrt(kor1sugara * kor1sugara - a * a);
            double pontXkoordinataja = kor1kozeppontX + a * (kor2kozeppontX - kor1kozeppontX) / ketKorTavolsaga;
            double ketKorElsoMetszespontXkoordinataja = pontXkoordinataja + h * (kor2kozeppontY - kor1kozeppontY) / ketKorTavolsaga;
            return ketKorElsoMetszespontXkoordinataja;
        }

        //Kiszámítja az első metszési pont Y koordinátáját.
        static double RepuloLehetsegesY1Koordinataja(double kor1kozeppontX, double kor1kozeppontY, double kor2kozeppontX, double kor2kozeppontY, double kor1sugara, double kor2sugara)
        {
            double iranyVektorX = kor1kozeppontX - kor2kozeppontX;
            double iranyVektorY = kor1kozeppontY - kor2kozeppontY;
            double ketKorTavolsaga = Math.Sqrt(iranyVektorX * iranyVektorX + iranyVektorY * iranyVektorY);
            double a = (kor1sugara * kor1sugara - kor2sugara * kor2sugara + ketKorTavolsaga * ketKorTavolsaga) / (2 * ketKorTavolsaga);
            double h = Math.Sqrt(kor1sugara * kor1sugara - a * a);
            double pontYkoordinataja = kor1kozeppontY + a * (kor2kozeppontY - kor1kozeppontY) / ketKorTavolsaga;
            double ketKorElsoMetszespontYkoordinataja = pontYkoordinataja - h * (kor2kozeppontX - kor1kozeppontX) / ketKorTavolsaga;
            return ketKorElsoMetszespontYkoordinataja;
        }

        //Kiszámítja a második metszési pont X koordinátáját.
        static double RepuloLehetsegesX2Koordinataja(double kor1kozeppontX, double kor1kozeppontY, double kor2kozeppontX, double kor2kozeppontY, double kor1sugara, double kor2sugara)
        {
            double iranyVektorX = kor1kozeppontX - kor2kozeppontX;
            double iranyVektorY = kor1kozeppontY - kor2kozeppontY;
            double ketKorTavolsaga = Math.Sqrt(iranyVektorX * iranyVektorX + iranyVektorY * iranyVektorY);
            double a = (kor1sugara * kor1sugara - kor2sugara * kor2sugara + ketKorTavolsaga * ketKorTavolsaga) / (2 * ketKorTavolsaga);
            double h = Math.Sqrt(kor1sugara * kor1sugara - a * a);
            double pontXkoordinataja = kor1kozeppontX + a * (kor2kozeppontX - kor1kozeppontX) / ketKorTavolsaga;
            double ketKorMasodikMetszespontXkoordinataja = pontXkoordinataja - h * (kor2kozeppontY - kor1kozeppontY) / ketKorTavolsaga;
            return ketKorMasodikMetszespontXkoordinataja;
        }

        //Kiszámítja a második metszési pont Y koordinátáját.
        static double RepuloLehetsegesY2Koordinataja(double kor1kozeppontX, double kor1kozeppontY, double kor2kozeppontX, double kor2kozeppontY, double kor1sugara, double kor2sugara)
        {
            double iranyVektorX = kor1kozeppontX - kor2kozeppontX;
            double iranyVektorY = kor1kozeppontY - kor2kozeppontY;
            double ketKorTavolsaga = Math.Sqrt(iranyVektorX * iranyVektorX + iranyVektorY * iranyVektorY);
            double a = (kor1sugara * kor1sugara - kor2sugara * kor2sugara + ketKorTavolsaga * ketKorTavolsaga) / (2 * ketKorTavolsaga);
            double h = Math.Sqrt(kor1sugara * kor1sugara - a * a);
            double pontYkoordinataja = kor1kozeppontY + a * (kor2kozeppontY - kor1kozeppontY) / ketKorTavolsaga;
            double ketKorMasodikMetszespontYkoordinataja = pontYkoordinataja + h * (kor2kozeppontX - kor1kozeppontX) / ketKorTavolsaga;
            return ketKorMasodikMetszespontYkoordinataja;
        }

        //16db tizedes helyett az X és Y koordinátákat 10db tizedesig kerekíti.
        static double[,] RepuloLehetsegesHelyzeteiKerekites(double[,] matrix)
        {
            Console.WriteLine("Yo");
            double[,] kerekitettMatrix = new double[matrix.GetLength(0), matrix.GetLength(1)];
            for (int i = 0; i < matrix.GetLength(0); i++)
            {
                for (int j = 0; j < matrix.GetLength(1); j++)
                {
                    kerekitettMatrix[i, j] = Math.Round(matrix[i, j], 10);
                }
            }
            return kerekitettMatrix;
        }

        //Visszaadja a három rádióállomás által mért (első és második időpillanatban a) gép pontos helyzetét koordinátáinak megadásával.
        //Ha nincsenek ilyen pontok a program leáll hibaüzenettel.
        static double[] RepuloMertHelyzetei(double[,] Matrix)
        {
            double[] Tomb = new double[4];

            if (((Matrix[0, 0] == Matrix[0, 4]) || (Matrix[0, 0] == Matrix[0, 6])) && ((Matrix[0, 0] == Matrix[0, 8]) || (Matrix[0, 0] == Matrix[0, 10]) && ((Matrix[0, 1] == Matrix[0, 5]) || (Matrix[0, 1] == Matrix[0, 7]) && ((Matrix[0, 1] == Matrix[0, 9]) || (Matrix[0, 1] == Matrix[0, 11])))))
            {
                Tomb[0] = Matrix[0, 0];
                Tomb[1] = Matrix[0, 1];
            }
            else if (((Matrix[0, 2] == Matrix[0, 4]) || (Matrix[0, 2] == Matrix[0, 6])) && ((Matrix[0, 2] == Matrix[0, 8]) || (Matrix[0, 2] == Matrix[0, 10]) && ((Matrix[0, 3] == Matrix[0, 5]) || (Matrix[0, 3] == Matrix[0, 7]) && ((Matrix[0, 3] == Matrix[0, 9]) || (Matrix[0, 3] == Matrix[0, 11])))))
            {
                Tomb[0] = Matrix[0, 2];
                Tomb[1] = Matrix[0, 3];
            }
            else
            {
                Console.WriteLine("Hiba! Az első időpillanatban a három radar nem mutat közös koordinátákra!");
                Console.Write("\nA kilépéshez nyomjon meg egy billentyűt!");
                Console.ReadLine();
                Environment.Exit(0);
            }

            if (((Matrix[1, 0] == Matrix[1, 4]) || (Matrix[1, 0] == Matrix[1, 6])) && ((Matrix[1, 0] == Matrix[1, 8]) || (Matrix[1,0] == Matrix[1,10]) && ((Matrix[1, 1] == Matrix[1, 5]) || (Matrix[1,1] == Matrix[1,7]) && ((Matrix[1, 1] == Matrix[1, 9]) || (Matrix[1,1] == Matrix[1,11])))))
            {
                Tomb[2] = Matrix[1, 0];
                Tomb[3] = Matrix[1, 1];
            }
            else if (((Matrix[1, 2] == Matrix[1, 4]) || (Matrix[1, 2] == Matrix[1, 6])) && ((Matrix[1, 2] == Matrix[1, 8]) || (Matrix[1, 2] == Matrix[1, 10]) && ((Matrix[1, 3] == Matrix[1, 5]) || (Matrix[1, 3] == Matrix[1, 7]) && ((Matrix[1, 3] == Matrix[1, 9]) || (Matrix[1, 3] == Matrix[1, 11])))))
            {
                Tomb[2] = Matrix[1, 2];
                Tomb[3] = Matrix[1, 3];
            }
            else
            {
                Console.WriteLine("Hiba! A második időpillanatban a három radar nem mutat közös koordinátákra!");
                Console.Write("\nA kilépéshez nyomjon meg egy billentyűt!");
                Console.ReadLine();
                Environment.Exit(0);
            }
            return Tomb;
        }

        //Példányosítja a repülőt.
        static Repulo RepuloLetrehozas(double[] Tomb)
        {
            double iranyvektorX = Tomb[2] - Tomb[0];
            double iranyvektorY = Tomb[3] - Tomb[1];
            Repulo repulo = new Repulo(Tomb[0], Tomb[1], Tomb[2], Tomb[3], iranyvektorX, iranyvektorY);
            return repulo;
        }

        //Példányosítja a városokat.
        //Negatív értékű sugár esetén a program leáll hibaüzenettel.
        static Varos[] VarosLetrehozas(double[,] Matrix)
        {
            Varos[] Varosok = new Varos[Matrix.GetLength(0)];
            for (int i = 0; i < Matrix.GetLength(0); i++)
            {
                if ((Matrix[i, 2] < 0) || (double.IsNaN(Matrix[i, 2])))
                {
                    int seged = i + 1;
                    Console.WriteLine("Hiba! A " +seged +". város sugara egy negatív szám!");
                    Console.Write("\nA kilépéshez nyomjon meg egy billentyűt!");
                    Console.ReadLine();
                    Environment.Exit(0);
                }
                else
                {
                    Varosok[i] = new Varos(Matrix[i, 0], Matrix[i, 1], Matrix[i, 2]);
                }
            }
            return Varosok;
        }

        //File-ba menti a feladat eredeményét.
        static void VarosKimenekites(Repulo repulo, Varos[] varosok)
        {
            StreamWriter sw = new StreamWriter("adatok.ki.txt");
            for (int i = 0; i < varosok.Length; i++)
            {
                if (RepuloUtvonalVSVaros(repulo.MasodikMertX, repulo.MasodikMertY, repulo.IranyvektorX, repulo.IranyvektorY, varosok[i].XKoordinata, varosok[i].YKoordinata, varosok[i].VarosSugara) == true)
                {
                    sw.WriteLine(varosok[i].XKoordinata + " " + varosok[i].YKoordinata);
                }
            }
            sw.Close();
        }

        //Megmondja, hogy a repülőgép érinti-e vagy átrepül-e az adott város felett.
        static bool RepuloUtvonalVSVaros(double masodikMertX, double masodikMertY, double iranyVektorX, double iranyVektorY, double xKoordinata, double yKoordinata, double varosSugara)
        {
            double A = 1 + (iranyVektorY / iranyVektorX) * (iranyVektorY / iranyVektorX);
            double B = -(2 * xKoordinata) - (2 * yKoordinata) * (iranyVektorY / iranyVektorX) + ((iranyVektorY / iranyVektorX) * (-((iranyVektorY * masodikMertX) / iranyVektorX)) + (iranyVektorY / iranyVektorX) * ((iranyVektorX * masodikMertY) / iranyVektorX) - ((iranyVektorY * masodikMertX) / iranyVektorX) * (iranyVektorY / iranyVektorX) + ((iranyVektorX * masodikMertY) / iranyVektorX) * (iranyVektorY / iranyVektorX));
            double C = (xKoordinata * xKoordinata) - ((iranyVektorY * masodikMertX) / iranyVektorX) * (-((iranyVektorY * masodikMertX) / iranyVektorX)) - ((iranyVektorY * masodikMertX) / iranyVektorX) * ((iranyVektorX * masodikMertY) / iranyVektorX) + ((iranyVektorX * masodikMertY) / iranyVektorX) * (-((iranyVektorY * masodikMertX) / iranyVektorX)) + ((iranyVektorX * masodikMertY) / iranyVektorX) * ((iranyVektorX * masodikMertY) / iranyVektorX) - (2 * yKoordinata) * (-((iranyVektorY * masodikMertX) / iranyVektorX)) - (2 * yKoordinata) * ((iranyVektorX * masodikMertY) / iranyVektorX) + (yKoordinata * yKoordinata) - (varosSugara * varosSugara);

            double D = B * B - (4 * A * C);

            if (D < 0)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
}
