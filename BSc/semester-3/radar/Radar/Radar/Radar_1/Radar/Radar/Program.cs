using System;
using System.IO;

namespace Radar
{
    class Program
    {
        static void Main(string[] args)
        {
            Radar[] radarAllomasok = RadarAllomasok(FileBeolvasas());
            Repulo repulo = RepuloLetrehozas(RepuloMertHelyzetei(RepuloLehetsegesHelyzeteiKerekites(RepuloLehetsegesHelyzetei(radarAllomasok))));
            Varos[] varosok = VarosLetrehozas(FileBeolvasas());
            VarosKimenekites(repulo, varosok);
            Console.WriteLine("A feladat eredménye mentésre került a munkakönyvtárban lévő 'adatok.ki' nevű txt file-ba!");
            Console.Write("\nA kilépéshez nyomjon meg egy billentyűt!");
            Console.ReadLine();
        }

        //Beolvassa a file tartalmát.
        static double[,] FileBeolvasas()
        {
            StreamReader sr = new StreamReader("adatok.be.txt");
            int VarosokSzama = int.Parse(sr.ReadLine());
            double[,] BeolvasottErtekek = new double[VarosokSzama+3, 4];
            for (int i = 0; i < BeolvasottErtekek.GetLength(0); i++)
            {
                string FileSora = sr.ReadLine();
                string[] FileSoranakSzetszedese = FileSora.Split(' ');
                int j = 0;
                while (j < FileSoranakSzetszedese.Length)
                {
                    BeolvasottErtekek[i, j] = SzamAtalakitasEsHibaElleneorzes(FileSoranakSzetszedese, j, i);
                    j++;
                }
            }
            sr.Close();
            return BeolvasottErtekek;
        }

        //Típuskonverziót hajt végre, közben hibaellenőrzést végez.
        static double SzamAtalakitasEsHibaElleneorzes(string[] sor, int indexJ, int indexI)
        {
            double Szam = 0;
            if (indexJ < 2)
            {
                Szam = double.Parse(sor[indexJ]);
            }
            else
            {
                if(sor[indexJ][0] == '-')
                {
                    HibaUzenet(indexI);
                    Console.ReadLine();
                    Environment.Exit(0);
                }
                else if (Char.IsLetter(sor[indexJ][0]))
                {
                    if (sor[indexJ][1] == '-')
                    {
                        HibaUzenet(indexI);
                        Console.ReadLine();
                        Environment.Exit(0);
                    }
                    else
                    {
                        string Seged = "";
                        for (int i = 1; i < sor[indexJ].Length; i++)
                        {
                            Seged = Seged + sor[indexJ][i];
                        }
                        Szam = Math.Sqrt(double.Parse(Seged));
                    }
                }
                else
                {
                    Szam = double.Parse(sor[indexJ]);
                }
            }
            return Szam;
        }

        //Megállapítja a hiba pontos okát.
        static void HibaUzenet(int indexI)
        {
            if (indexI < 3)
            {
                int Seged = indexI + 1;
                Console.WriteLine("Hiba! A " + Seged + ". radar által mért távolság egy negatív szám!");
            }
            else
            {
                int Seged = indexI - 2;
                Console.WriteLine("Hiba! A " + Seged + ". város sugara egy negatív szám!");
            }
            Console.Write("\nA kilépéshez nyomjon meg egy billentyűt!");
        }

        //Példányosítja a radarállomásokat
        static Radar[] RadarAllomasok(double[,] BeolvasottFile)
        {
            Radar[] radarAllomas = new Radar[3];
            for (int i = 0; i < 3; i++)
            {
                    radarAllomas[i] = new Radar(BeolvasottFile[i, 0], BeolvasottFile[i, 1], BeolvasottFile[i, 2], BeolvasottFile[i, 3]);
            }
            return radarAllomas;
        }

        //radar0 & radar1; radar0 & radar2; radar1 & radar2 közös pontjait határozza meg.
        static double[,] RepuloLehetsegesHelyzetei(Radar[] Tomb)
        {
            double[,] mertKoordinatak = new double[2, 12];
            for (int i = 0; i < mertKoordinatak.GetLength(0); i++)
            {
                for (int j = 0; j < mertKoordinatak.GetLength(1); j = j + 4)
                {
                    double[] KorokMetszesPontjai = new double[4];
                    if (i == 0)
                    {
                        if (j < 4)
                        {
                            KorokMetszesPontjai = RepuloLehetsegesXYKoordinatai(Tomb[0].Xkoordinata, Tomb[0].Ykoordinata, Tomb[1].Xkoordinata, Tomb[1].Ykoordinata, Tomb[0].Tavolsag1, Tomb[1].Tavolsag1);
                        }
                        else if ((j > 3) && (j < 8))
                        {
                            KorokMetszesPontjai = RepuloLehetsegesXYKoordinatai(Tomb[0].Xkoordinata, Tomb[0].Ykoordinata, Tomb[2].Xkoordinata, Tomb[2].Ykoordinata, Tomb[0].Tavolsag1, Tomb[2].Tavolsag1);
                        }
                        else
                        {
                            KorokMetszesPontjai = RepuloLehetsegesXYKoordinatai(Tomb[1].Xkoordinata, Tomb[1].Ykoordinata, Tomb[2].Xkoordinata, Tomb[2].Ykoordinata, Tomb[1].Tavolsag1, Tomb[2].Tavolsag1);
                        }
                    }
                    else
                    {
                        if (j < 4)
                        {
                            KorokMetszesPontjai = RepuloLehetsegesXYKoordinatai(Tomb[0].Xkoordinata, Tomb[0].Ykoordinata, Tomb[1].Xkoordinata, Tomb[1].Ykoordinata, Tomb[0].Tavolsag2, Tomb[1].Tavolsag2);
                        }
                        else if ((j > 3) && (j < 8))
                        {
                            KorokMetszesPontjai = RepuloLehetsegesXYKoordinatai(Tomb[0].Xkoordinata, Tomb[0].Ykoordinata, Tomb[2].Xkoordinata, Tomb[2].Ykoordinata, Tomb[0].Tavolsag2, Tomb[2].Tavolsag2);
                        }
                        else
                        {
                            KorokMetszesPontjai = RepuloLehetsegesXYKoordinatai(Tomb[1].Xkoordinata, Tomb[1].Ykoordinata, Tomb[2].Xkoordinata, Tomb[2].Ykoordinata, Tomb[1].Tavolsag2, Tomb[2].Tavolsag2);
                        }
                    }
                    mertKoordinatak[i, j] = KorokMetszesPontjai[0];
                    mertKoordinatak[i, j + 1] = KorokMetszesPontjai[1];
                    mertKoordinatak[i, j + 2] = KorokMetszesPontjai[2];
                    mertKoordinatak[i, j + 3] = KorokMetszesPontjai[3];
                }
            }
            return mertKoordinatak;
        }

        //Kiszámolja két kör összes metszéspontját.
        static double[] RepuloLehetsegesXYKoordinatai(double kor1kozeppontX, double kor1kozeppontY, double kor2kozeppontX, double kor2kozeppontY, double kor1sugara, double kor2sugara)
        {
            double[] Tomb = new double[4];
            double iranyVektorX = kor1kozeppontX - kor2kozeppontX;
            double iranyVektorY = kor1kozeppontY - kor2kozeppontY;
            double ketKorTavolsaga = Math.Sqrt(iranyVektorX * iranyVektorX + iranyVektorY * iranyVektorY);
            double a = (kor1sugara * kor1sugara - kor2sugara * kor2sugara + ketKorTavolsaga * ketKorTavolsaga) / (2 * ketKorTavolsaga);
            double h = Math.Sqrt(kor1sugara * kor1sugara - a * a);
            double pontXkoordinataja = kor1kozeppontX + a * (kor2kozeppontX - kor1kozeppontX) / ketKorTavolsaga;
            double pontYkoordinataja = kor1kozeppontY + a * (kor2kozeppontY - kor1kozeppontY) / ketKorTavolsaga;
            Tomb[0] = pontXkoordinataja + h * (kor2kozeppontY - kor1kozeppontY) / ketKorTavolsaga;
            Tomb[1] = pontYkoordinataja - h * (kor2kozeppontX - kor1kozeppontX) / ketKorTavolsaga;
            Tomb[2] = pontXkoordinataja - h * (kor2kozeppontY - kor1kozeppontY) / ketKorTavolsaga;
            Tomb[3] = pontYkoordinataja + h * (kor2kozeppontX - kor1kozeppontX) / ketKorTavolsaga;

            return Tomb;
        }

        //16db tizedes helyett az X és Y koordinátákat 10db tizedesig kerekíti.
        static double[,] RepuloLehetsegesHelyzeteiKerekites(double[,] matrix)
        {
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
            int Seged = 0;
            for (int i = 0; i < Matrix.GetLength(0); i++)
            {
                if (((Matrix[i, 0] == Matrix[i, 4]) || (Matrix[i, 0] == Matrix[i, 6])) && ((Matrix[i, 0] == Matrix[i, 8]) || (Matrix[i, 0] == Matrix[i, 10]) && ((Matrix[i, 1] == Matrix[i, 5]) || (Matrix[i, 1] == Matrix[i, 7]) && ((Matrix[i, 1] == Matrix[i, 9]) || (Matrix[i, 1] == Matrix[i, 11])))))
                {
                    Tomb[Seged] = Matrix[i, 0]; Seged++;
                    Tomb[Seged] = Matrix[i, 1]; Seged++;
                }
                else if (((Matrix[i, 2] == Matrix[i, 4]) || (Matrix[i, 2] == Matrix[i, 6])) && ((Matrix[i, 2] == Matrix[i, 8]) || (Matrix[i, 2] == Matrix[i, 10]) && ((Matrix[i, 3] == Matrix[i, 5]) || (Matrix[i, 3] == Matrix[i, 7]) && ((Matrix[i, 3] == Matrix[i, 9]) || (Matrix[i, 3] == Matrix[i, 11])))))
                {
                    Tomb[Seged] = Matrix[0, 2]; Seged++;
                    Tomb[Seged] = Matrix[0, 3]; Seged++;
                }
                else
                {
                    HibaUzenet2(i);
                    Console.ReadLine();
                    Environment.Exit(0);
                }
            }
            return Tomb;
        }

        //Megmondja a hiba pontos okát.
        static void HibaUzenet2(int index)
        {
            if (index == 0)
            {
                Console.WriteLine("Hiba! Az első időpillanatban a három radar nem mutat közös koordinátákra!");
                Console.Write("\nA kilépéshez nyomjon meg egy billentyűt!");
            }
            else
            {
                Console.WriteLine("Hiba! A második időpillanatban a három radar nem mutat közös koordinátákra!");
                Console.Write("\nA kilépéshez nyomjon meg egy billentyűt!");
            }
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
        static Varos[] VarosLetrehozas(double[,] BeolvasottFile)
        {
            Varos[] Varosok = new Varos[BeolvasottFile.GetLength(0)-3];
            int SegedIndexelo = 0;
            for (int i = 3; i < BeolvasottFile.GetLength(0); i++)
            {
                Varosok[SegedIndexelo] = new Varos(BeolvasottFile[i, 0], BeolvasottFile[i, 1], BeolvasottFile[i, 2]);
                SegedIndexelo++;
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
