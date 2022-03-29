#include <iostream>
#include <chrono>
struct ArrayList
{
    int* bas;
    void olustur(int);
    void ekle(int, int);
    void guncelle(int, int);
    void sil(int);
    void yazdir();
    void bosalt();
    int sayac;
};
struct Node
{
    int deger;
    Node* sonraki;
};
struct LinkedList
{
    Node* bas;
    void olustur();
    void ekle(int , int);
    void guncelle(int, int);
    void sil(int);
    void yazdir();
    void bosalt();
    int sayac;

};

int main()
{
    
    LinkedList* linkedList = new LinkedList();
    ArrayList* arrayList = new ArrayList();    
    arrayList->olustur(2000);
    linkedList->olustur();
    std::cout << "2000 elemanli listede: \n";
    auto begin = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 2000; i++)
    {
       linkedList->ekle(7, 0);
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    std::cout << "Linkedlist ile ekleme suresi  =>" << elapsed.count() << "mikro-saniye" << std::endl;
    
    auto beginn = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 2000; i++)
    {
        arrayList->ekle(7, 0);
    }

    auto endn = std::chrono::high_resolution_clock::now();
    auto elapsedn = std::chrono::duration_cast<std::chrono::microseconds>(endn - beginn);
    std::cout << "Arraylist ile ekleme suresi  =>" << elapsedn.count() << "mikro-saniye" << std::endl;
}

void LinkedList::olustur() {
    bas = NULL;
}
void LinkedList::ekle(int eklenecekDeger,int eklenecekSýra){
    Node *node = new Node();
    node->deger = eklenecekDeger;
    if (bas == NULL) {
        bas = node;
        return;
    }
    Node *tara;
    tara = bas;
    int index = 0;
    while (tara->sonraki) {
        if (index == eklenecekSýra-1)
        {   
            node->sonraki = tara->sonraki;
            tara->sonraki = node;            
            return;
            
        }
        if (eklenecekSýra==0)
        {
            node->sonraki = tara;
            bas = node;
            return;
        }
        else
        {   
            tara = tara->sonraki;
            index++;
        }
            
    }
    if (index+1 >= eklenecekSýra)
    {
        tara->sonraki = node;
        return;
    }
    else
    {
        throw "Liste sinirlarin disindaydi.";
    }
}
void LinkedList::yazdir() {
    Node* tara;
    tara = bas;
    if (!tara) {
        std::cout << "Liste bos!!!" ;
        return;
    }
    while (tara) {
        std::cout << tara->deger << " ";
        tara = tara->sonraki;
    }
    std::cout << "\n";
}
void LinkedList::sil(int silinecekyer) {
    Node* temp;
    Node* silinecekNode;
    temp = bas;
    if (silinecekyer==0)
    {
        bas = bas->sonraki;
        free(temp);
        return;
    }
    while (silinecekyer-1 >= 0)
    {
        if (silinecekyer == 1)
        {
            silinecekNode = temp->sonraki;
            temp->sonraki = temp->sonraki->sonraki;
            free(silinecekNode);
            return;
        }
        else
        {
            temp = temp->sonraki;
            silinecekyer--;
        }

    }
    

}
void LinkedList::guncelle(int guncellenecekDeger, int guncellenecekSýra) {
    Node* tara;
    tara = bas;
    while (guncellenecekSýra!=0)
    {
        guncellenecekSýra--;
        tara = tara->sonraki;
    }
    tara->deger = guncellenecekDeger;

}
void LinkedList::bosalt() {
    Node* tara;
    while (bas!=NULL)
    {      
        tara = bas;
        bas = bas->sonraki;
        free(tara);
    }
}
void ArrayList::olustur(int maxBoyut) {
    bas = new int[maxBoyut];
}
void ArrayList::ekle(int eklenecekDeger, int eklenecekSýra) {
    if (sayac==eklenecekSýra)
    {
        bas[eklenecekSýra] = eklenecekDeger;
        sayac++;
    }
    
    else if(eklenecekSýra>sayac)
    {
        throw "Dizi sinirlrinin disina cikdiniz.";
    }
    else
    {
        int j = 0;
        int fark = sayac - eklenecekSýra;
        while (fark!=0)
        {
            bas[sayac  - j] = bas[sayac-1- j];
            j++;
            fark--;
        }
        bas[eklenecekSýra] = eklenecekDeger;
        sayac++;
    }
}
void ArrayList::yazdir() {
    for (int i = 0; i < sayac; i++)
    {
            std::cout << bas[i];
            std::cout << " ";
        
    }
}
void ArrayList::bosalt() {
    delete []bas;
}
void ArrayList::guncelle(int guncellenecekDeger, int guncellenecekSýra) {
    bas[guncellenecekSýra] = guncellenecekDeger;
}
void ArrayList::sil(int silinecekyer){

    if (silinecekyer<=sayac-1)
    {
        for (int i = 0; i < sayac-silinecekyer; i++)
        {
            bas[silinecekyer + i] = bas[silinecekyer + 1 + i];
        }
        sayac--;
    }
    else
    {
        throw "Dizi sinirlari disina cikdiniz.";
    }
}



