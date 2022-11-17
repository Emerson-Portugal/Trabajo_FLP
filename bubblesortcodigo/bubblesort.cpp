#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& a)
{
      bool swapp = true;
      while(swapp){
        swapp = false;
        for (size_t i = 0; i < a.size()-1; i++) {
            if (a[i]>a[i+1] ){
                a[i] += a[i+1];
                a[i+1] = a[i] - a[i+1];
                a[i] -=a[i+1];
                swapp = true;
            }
        }
    }
}

vector<int> slicing(vector<int> arr, int min, int max){
    auto start = arr.begin()+min;
    auto end = arr.begin()+max+1;

    vector<int> result(max-min+1);

    copy(start, end, result.begin());

    return result;
}

vector<vector<int>> generarlistas(string file)
{
    int number;
    vector<int> nums{};
    vector<vector<int>> listadatos{};
    vector<int> temp{};
    int e[]={100,1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000,
    9000, 10000, 20000, 30000, 40000, 50000};

    ifstream input_file(file);

    while (input_file >> number) {
        nums.push_back(number);
    }

    for (int i = 0; i < 15; i++)
    {   
        temp = slicing(nums,0,e[i]-1);
        listadatos.push_back(temp);
    }
    
    return listadatos;

}
 
int main()

{   
    ofstream file;
    file.open("D:/Camino_Emerson/LA SALLE_Semestre_5_6/Fundamentos_Lenguajes(Pack)/Carpeta_Emer_ACTUAL/Proyecto Final/python_vs_golang_c--main/tiemposejecucionbubble/tiemposc++.txt");
    ofstream file2;
    file2.open("D:/Camino_Emerson/LA SALLE_Semestre_5_6/Fundamentos_Lenguajes(Pack)/Carpeta_Emer_ACTUAL/Proyecto Final/python_vs_golang_c--main/desviacionestandarbubble/desviacionestarc++.txt");
    int e[]={100,1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000,
    9000, 10000, 20000, 30000, 40000, 50000};
    
    vector<vector<int>> listas{};
    string datos = "datos";
    
   for(int i=0;i<15;i++){
        double t[5];
        for(int j=0;j<5;j++){
            
            listas = generarlistas("D:/Camino_Emerson/LA SALLE_Semestre_5_6/Fundamentos_Lenguajes(Pack)/Carpeta_Emer_ACTUAL/Proyecto Final/python_vs_golang_c--main/"+datos+to_string(j+1)+".txt");
            unsigned t0, t1;
            
    
            t0=clock();
            bubbleSort(listas[i]);
            t1=clock();
    
            double time = (double(t1-t0)/CLOCKS_PER_SEC);
            t[j] = time;
        }
        double prom = 0;
        for (int k=0;k<5;k++){
            prom += t[k];
        }
        double promf = prom/5;

        double des = 0;
        for (int d=0;d<5;d++){
            des += pow((t[d]-promf),2);
        }
        des=sqrt(des/4);

        file<<promf<<"\n";
        file2<<des<<"\n";
        cout<<"promedio array de tamaño "<<e[i]<<": "<<promf<<" Desviacion Estandar: "<<des<<endl;

   }

   file.close();
   file2.close();
    return 0;
}