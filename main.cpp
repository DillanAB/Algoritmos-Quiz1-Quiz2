#include <iostream>
#include <vector>
using namespace std;
//Análisis de algoritmos - Quiz#1 Quiz#2
//Dillan Almendares Barrantes
//2020033336


class Noticia{
public:
    string titulo;
    string fecha;
    string reportero;
    virtual void getInfo() = 0;
};

class NoticiaPaper : public Noticia{
private:
    string ruta;
public:
    NoticiaPaper(string ruta){
        this->ruta = ruta;
    }
    virtual void getInfo(){
        cout<<reportero<<endl;
        cout<<titulo<<endl;
        cout<<fecha<<endl;
        cout<<ruta<<endl;
        return;
    }
    string getRuta(){
        return ruta;
    }
};

class NoticiaDigital : public Noticia{
private:
    vector<string> listaMedia;
public:
    NoticiaDigital(vector<string> lista){
        this->listaMedia = lista;
    }
    virtual void getInfo(){
        cout<<titulo<<endl;
        cout<<reportero<<"  "<<fecha<<endl;
        for (int i=0; i<listaMedia.size(); i++){
            cout<<listaMedia[i]<<endl;
        }
        return;
    }
};

class NoticiaRadio : public Noticia{
private:
    string url;
public:
    NoticiaRadio(string url){
        this->url = url;
    }
    virtual void getInfo(){
        cout<<titulo<<endl;
        cout<<"Link: "<<url<<endl;
        cout<<reportero<<"  "<<fecha<<endl;
        return;
    }
    string getUrl(){
        return url;
    }
};


int main(int argc, char** argv){
    cout<<endl<<endl;
    NoticiaPaper* nPaper = new NoticiaPaper("C:\\Users\\Dillan\\Pictures");
    nPaper->titulo = "Biden anuncia cierre del espacio aereo de EE.UU. a aerolineas rusas";
    nPaper->reportero = "DW";
    nPaper->fecha = "3/1/2022";

    vector<string> l = {"Foto1.jpg", "Video.mp4", "Audio.mp3", "Foto2.png"};
    NoticiaDigital* nDigital = new NoticiaDigital(l);
    nDigital->titulo = "Mapache ayuda a senora a cruzar la calle";
    nDigital->reportero = "Teletica";
    nDigital->fecha = "13/2/2077";


    NoticiaRadio* nRadio = new NoticiaRadio("https://soundcloud.com/bbcnewsdev/27629-north-korea-to-dismantle?utm_source=clipboard&utm_medium=text&utm_campaign=social_sharing");
    nRadio->titulo = "North Korea to dismantle nuclear site in May ceremony";
    nRadio->reportero = "BBC";
    nRadio->fecha = "11/9/2019";

    Noticia* nArray[] = {nPaper, nDigital, nRadio};
    for(int i=0; i<3;i++){
        cout<<"Noticia: "<<i+1<<endl;
        nArray[i]->getInfo();
        cout<<endl<<endl;
    }
    
    return 0;
}