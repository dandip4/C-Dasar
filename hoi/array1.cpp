#include <iostream> 
#include <conio.h>  
#include <fstream>
#include <ctime>

#define MAX 100

using namespace std;

int nomer[MAX];
int data=-1, tail=-1;

bool IsEmpty(){ 
   if(tail == -1){
       return true;
   }else{ 
       return false;
   }
}
bool IsFull(){  
   if(tail == MAX-1){
       return true;
   }else{
       return false;
   }
}
void AntrianMasuk(int no){ 
    if (IsEmpty()){
        data=tail=0;
    }else {
        tail++;
    }
    nomer[tail]=no;
}
void AntrianKeluar(){
    if(IsEmpty()){
        cout<<"Antrian sudah kosong ! "; 
        getch();
    } else {
        for(int a=data;a<tail;a++){
            nomer[a]=nomer[a+1];
        }
        tail--;
        if(tail == -1){
            data = -1; 
        }
    }
}

struct mn
{
    int jumlah[100],sub_total[100],harga[100],No_barang[100];
    string menu[100];
};


void Clear(){
    data = tail = -1;
}



int main(){
   
    mn barang;
    int total_bayar;
    int i=0;
    int pilihan, pilih[100];
    int  p = 1, urut, r = 1,ch;


    do{
      system("cls");   

    kosong:
    cout << "                PROGRAM AL-UNPAK              \n";
    cout << "|--------------------------------------------|\n";
    cout << "|1. Tambah Antrian                           |\n";
    cout << "|2. Panggil Antrian                          |\n";
    cout << "|3. Kosongkan Antrian                        |\n";
    cout << "|4. Exit                                     |\n";
    cout << "Pilih : "; cin >> pilihan;

    cout << "\n\n";

    
    if (pilihan == 1){
        if(IsFull()){
            cout << "Antrian Sudah Penuh, Mohon ditunggu";
        }else {
            // r = p;
            AntrianMasuk(pilihan);
    cout << "\n|--------------------------------------------|\n";
    cout << "|Nomer Antrian Anda : " << p;
    cout << "\n|--------------------------------------------|\n";
    cout << "|Silahkan mengantri, Menunggu " << tail << " " <<  "Antrian";
    cout << "\n|--------------------------------------------|\n";
    p++;
        }
    }
    else if(pilihan == 2){
    menu:
    system("cls");

    if(IsEmpty()){
        cout << "|            Antrian sudah kosong !          |\n\n";
        goto kosong;
        getch();
    }else{
        for(int a = data ; a < tail ; a++){
            nomer[a] = nomer[a+1];
        }
        r++;
        tail--;
        if(tail == -1){
            data = -1;
        }
    }


    cout << "|=======================================================================================|" <<endl;
    cout << "|                                                                                       |" <<endl;
    cout << "|                                      ALFAMART                                         |" <<endl;
    cout << "|                                   Cibinong bogor                                      |" <<endl;
    cout << "|=======================================================================================|" <<endl;
    cout << "|=======================================================================================|" <<endl;
    cout << "|                                     DAFTAR MENU                                       |" <<endl;
    cout << "|=======================================================================================|" <<endl;
    cout << "|1. Tic Tac 100 g              : Rp. 6.500            6. Susu UHT 115 ml    : Rp. 7.300 |" <<endl;
    cout << "|2. Lifebouy sabun mandi cair  : Rp. 28.900           7. Beng-beng          : Rp. 5.000 |" <<endl;
    cout << "|3. Cadbury Chocolate Dairy 30g: Rp. 8.200            8. Qtela 180 g        : Rp. 15.000|" <<endl;
    cout << "|4. Silver Queen Chocolate 33g : Rp. 8.400            9. Chitato 168 g      : Rp. 27.000|" <<endl;
    cout << "|5. Kacang Atom Garuda 130 gr  : Rp. 9.300            10. Piattos 75 g      : Rp. 9.900 |" <<endl;
    cout << "|=======================================================================================|" <<endl;


    bool selesai=false;
   
    cout << "tekan 0 jika selesai melakukan pemesanan" <<endl;

    while (selesai==false){
        cout << "pilih menu : ";
        cin >>pilih[i];

        if(pilih [i]<=10){
        if(pilih[i]==0){
            selesai=true;

            }else{

            switch (pilih[i]){
            case 1 : barang.menu[i]="Tic Tac 100 g ";
                    barang.harga[i]=6500;
                    break;
            case 2 : barang.menu[i]="Lifebouy sabun mandi cair";
                    barang.harga[i]= 28900;
                    break;
            case 3 : barang.menu[i]="Cadbury Chocolate Dairy 30g";
                    barang.harga[i]=8200;
                    break;
            case 4 : barang.menu[i]="Silver Queen Chocolate 33g";
                    barang.harga[i]=8400;
                    break;
            case 5 : barang.menu[i]="Kacang Atom Garuda 130 gr";
                    barang.harga[i]=19300;
                    break;
            case 6: barang.menu[i]="Susu UHT 115 ml";
                    barang.harga[i]=7300;
                    break;
            case 7 : barang.menu[i]="beng-beng";
                    barang.harga[i]=5000;
                    break;
            case 8 : barang.menu[i]="Qtela 180 g";
                    barang.harga[i]=15000;
                    break;
            case 9 : barang.menu[i]="Chitato 168 g";
                    barang.harga[i]=27000;
                    break;    
            case 10 : barang.menu[i]="Piattos 75 g";
                    barang.harga[i]=9000;
                    break;
            default : barang.menu[i]=" ";
                     barang.harga[i]=0;
                     break;
           }

           cout << "jumlah barang "<<barang.menu[i]<<"  : ";
           cin>>barang.jumlah[i];
           cout <<endl;

           barang.sub_total[i]=barang.jumlah[i]*barang.harga[i];
           total_bayar+=barang.sub_total[i];
           i++;

        }
     
        }else{
            cout << "menu yang di pilih tida sesuai" <<endl;
            cout << endl;

        }
    }

    system("cls");
    cout << "Nota Pembayaran";

    for(int a=0;a<i;a++){
    
       barang.menu[a];
       cout << endl;
       cout << "-------------------------"<<endl;
       cout <<a+1<<endl;
       cout << "Harga Satuan : " <<barang.menu[a] << endl;
       cout << "harga        : " <<barang.harga[a]<<endl;
       cout << "jumlah       : " <<barang.jumlah[a]<<endl;
       cout << "total        : " <<barang.sub_total[a]<<endl;
       cout << "------------------------"<<endl;
    
        
       time_t waktu = time(0);
       char* tanggal = ctime(&waktu);

    ofstream nota_pembayaran;
    nota_pembayaran.open("struk.txt");

    nota_pembayaran << "                   STRUK PEMBAYARAN ALFAMART\n";
    nota_pembayaran << "                       AL-UNPAK BOGOR\n";

    nota_pembayaran << endl;
    nota_pembayaran << "                 Tanggal dan Waktu Pembayaran\n";
    nota_pembayaran << "                   " << tanggal;

    nota_pembayaran << endl;
    nota_pembayaran << "             -----------------------------------\n";
   
    nota_pembayaran << "Harga Satuan : " <<barang.menu[a] << endl;
    nota_pembayaran << "harga        : " <<barang.harga[a]<<endl;
    nota_pembayaran << "jumlah       : " <<barang.jumlah[a]<<endl;
    nota_pembayaran << "total        : " <<barang.sub_total[a]<<endl; 
    
    nota_pembayaran << "============================="<<endl;  
    nota_pembayaran << "total bayar = Rp."<<total_bayar<<endl;
    nota_pembayaran << "============================="<<endl;  

    nota_pembayaran << "             -----------------------------------\n";
    nota_pembayaran << "                            Terima Kasih"; 
            

    nota_pembayaran.close();
    
    }
           
    cout << "============================="<<endl;  
    cout << "total bayar = Rp."<<total_bayar<<endl;
    cout << "============================="<<endl;  
    

    // barang.menu[i] = NULL;
    }else if(pilihan == 3){
        Clear();
        cout << "Antrian Kosong ";
    }else if(pilihan ==4){
        
    }else{
        cout << "Menu yang anda pilih tidak tersedia\n";
    }
    getch();
    }while(pilihan!=4);
}