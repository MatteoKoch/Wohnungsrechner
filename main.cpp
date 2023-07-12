#include <iostream>
#include <windows.h>

using namespace std;

int ann_tilgung(float darlehen, float zins, float tilgung) {
    float restschuld = darlehen;
    float satz = 0.01 * (zins+tilgung) * darlehen;

    int jahr = 0;
    while(restschuld > 0) {
        jahr++;
        tilgung = satz - (0.01*zins*restschuld);
        restschuld -= tilgung;
    }
    return jahr;
}

int main()
{

    float zins, tilgung;
    float preis, miete, ruecklagen, umlage, flaeche;

    cout<<"Angaben zur Wohnung\n\n";
    cout<<"Wohnungspreis: ";
    cin>>preis;
    cout<<"\nFlaeche(in qm): ";
    cin>>flaeche;
    cout<<"\nMonatl. Ruecklagen: ";
    cin>>ruecklagen;
    cout<<"\nNicht umlagefahig.: ";
    cin>>umlage;
    cout<<"\nMiete: ";
    cin>>miete;
    system("cls");
    cout<<"Angaben zur Finanzierung\n\n";
    cout<<"Vereinbarter Zinssatz: ";
    cin>>zins;
    cout<<"\nTilgung: ";
    cin>>tilgung;
    system("cls");

    float darlehen = preis * 1.1;
    cout<<"Darlehen: "<<darlehen<<"EUR\n\n";
    cout<<"Dein Darlehen ist bei einer Rate von "<<0.01 * (zins+tilgung) * darlehen/12<<"EUR nach "<<ann_tilgung(darlehen, zins, tilgung)<<" Jahren abbezahlt!\n\n";
    cout<<"Preis pro Quadratmeter: "<<preis/flaeche<<"EUR\n\n";
    float monat = miete - (ruecklagen + umlage + (0.01*(zins+tilgung)*darlehen/12));
    cout<<"Monatsende: "<<monat<<"EUR\n\n";
    float steuern = 0.38 * (miete - ((0.01*zins*darlehen/12) + umlage + (0.02*preis/12)));
    cout<<"Steuern: "<<steuern<<"EUR\n\n";
    cout<<"Monatsende abzgl. Steuern (Cashflow): "<<monat - steuern<<"EUR\n\n";
    cout<<"Reiner Cashflow nach einem Jahr: "<<12*(monat - steuern)<<"EUR\nReiner Cashflow nach vollstaendiger Tilgung: "<<ann_tilgung(darlehen, zins, tilgung)*12*(monat - steuern)<<"EUR\n\n";

    return 0;
}
