#include<iostream>
#include<fstream>
#include <cstring>

using namespace std;

void init(char denumire[25],char codprodus[10])
{
	cout<<"Denumire produs : ";
	cin.getline(denumire,25);
	cout<<'\n'<<"Cod produs : ";
	cin>>codprodus;
	/*char a;
	cout<<"Datele introduse sunt corecte? (d/n) ";
	cin>>a;
	if(a=='n')
		init(denumire,codprodus);*/ // trece peste getline
}
void verif(char codprodus[13],char ean13[13])
{
	int i=0;
	while(codprodus[i]>='0'&&codprodus[i]<='9')
		i++;
	if(i!=strlen(codprodus))
	{
		cerr<<"Codul produsului este gresit!!! "<<endl;
		cout<<"Reintroduceti:"<<endl;
		cin>>codprodus;
	}
	char sirSapte[9];
	while(strlen(codprodus)>9)
	{
		cerr<<"Cod introdus este prea lung"<<endl;
		cout<<"Reintroduceti cod produs:"<<endl;
		cin>>codprodus;
	}
	if(strlen(codprodus)<9)
	{
		int j;
		for(j=0;j<(9-(strlen(codprodus)));j++)
			sirSapte[j] = '7';
		sirSapte[j] = '\0';
		strcpy(ean13,"594");
		strcat(ean13,sirSapte);
		strcat(ean13,codprodus);
	}
	if(strlen(codprodus)==9)
	{
		strcpy(ean13,"594");
		strcat(ean13,codprodus);
	}
}
int cifraCtrl(int nean13[13])
{
	int s1,s2,S;
	s1 = s2 = S =0;
	for(int i=0;i<12;i=i+2)
	{
		s1=s1+nean13[i];
		s2=s2+nean13[i+1];
	}
	S=s1+3*s2;
	nean13[12]=10-S%10;
	return nean13[12];
}
void afisareCod(int nean13[13])
{
	cout<<"codul complet este : ";
	for(int i=0;i<13;i++)
		cout<<nean13[i];
	cout<<endl;
}
void Lcode(int valoare, int bin[], int poz)
{
	switch(valoare)
	{
	case 0: // 0001101
		cout<<valoare<<'\t'<<"0001101"<<endl;
		bin[poz]=bin[poz+1]=bin[poz+2]=bin[poz+5]=0;
		bin[poz+3]=bin[poz+4]=bin[poz+6]=1;
		break;
	case 1: // 0011001
		cout<<valoare<<'\t'<<"0011001"<<endl;
		bin[poz]=bin[poz+1]=bin[poz+4]=bin[poz+5]=0;
		bin[poz+2]=bin[poz+3]=bin[poz+6]=1;
		break;
	case 2: // 0010011
		cout<<valoare<<'\t'<<"0010011"<<endl;
		bin[poz]=bin[poz+1]=bin[poz+3]=bin[poz+4]=0;
		bin[poz+2]=bin[poz+5]=bin[poz+6]=1;
		break;
	case 3: // 0111101
		cout<<valoare<<'\t'<<"0111101"<<endl;
		bin[poz]=bin[poz+5]=0;
		bin[poz+1]=bin[poz+2]=bin[poz+3]=bin[poz+4]=bin[poz+6]=1;
		break;
	case 4: // 0100011
		cout<<valoare<<'\t'<<"0100011"<<endl;
		bin[poz]=bin[poz+2]=bin[poz+3]=bin[poz+4]=0;
		bin[poz+1]=bin[poz+5]=bin[poz+6]=1;
		break;
	case 5: // 0110001
		cout<<valoare<<'\t'<<"0110001"<<endl;
		bin[poz]=bin[poz+3]=bin[poz+4]=bin[poz+5]=0;
		bin[poz+1]=bin[poz+2]=bin[poz+6]=1;
		break;
	case 6: // 0101111
		cout<<valoare<<'\t'<<"0101111"<<endl;
		bin[poz]=bin[poz+2]=0;
		bin[poz+1]=bin[poz+3]=bin[poz+4]=bin[poz+5]=bin[poz+6]=1;
		break;
	case 7: // 0111011
		cout<<valoare<<'\t'<<"0111011"<<endl;
		bin[poz]=bin[poz+4]=0;
		bin[poz+1]=bin[poz+2]=bin[poz+3]=bin[poz+5]=bin[poz+6]=1;
		break;
	case 8: // 0110111
		cout<<valoare<<'\t'<<"0110111"<<endl;
		bin[poz]=bin[poz+3]=0;
		bin[poz+1]=bin[poz+2]=bin[poz+4]=bin[poz+5]=bin[poz+6]=1;
		break;
	case 9: // 0001011
		cout<<valoare<<'\t'<<"0001011"<<endl;
		bin[poz]=bin[poz+1]=bin[poz+2]=bin[poz+4]=0;
		bin[poz+3]=bin[poz+5]=bin[poz+6]=1;
		break;
	}
}
void Gcode(int valoare, int bin[], int poz)
{
	switch(valoare)
	{
	case 0: // 0100111
		cout<<valoare<<'\t'<<"0100111"<<endl;
		bin[poz]=bin[poz+2]=bin[poz+3]=0;
		bin[poz+1]=bin[poz+4]=bin[poz+5]=bin[poz+6]=1;
		break;
	case 1: // 0110011
		cout<<valoare<<'\t'<<"0110011"<<endl;
		bin[poz]=bin[poz+3]=bin[poz+4]=0;
		bin[poz+1]=bin[poz+2]=bin[poz+5]=bin[poz+6]=1;
		break;
	case 2: // 0011011
		cout<<valoare<<'\t'<<"0011011"<<endl;
		bin[poz]=bin[poz+1]=bin[poz+4]=0;
		bin[poz+2]=bin[poz+3]=bin[poz+5]=bin[poz+6]=1;
		break;
	case 3: // 0100001
		cout<<valoare<<'\t'<<"0100001"<<endl;
		bin[poz]=bin[poz+2]=bin[poz+3]=bin[poz+4]=bin[poz+5]=0;
		bin[poz+1]=bin[poz+6]=1;
		break;
	case 4: // 0011101
		cout<<valoare<<'\t'<<"0011101"<<endl;
		bin[poz]=bin[poz+1]=bin[poz+5]=0;
		bin[poz+2]=bin[poz+3]=bin[poz+4]=bin[poz+6]=1;
		break;
	case 5: // 0111001
		cout<<valoare<<'\t'<<"0111001"<<endl;
		bin[poz]=bin[poz+4]=bin[poz+5]=0;
		bin[poz+1]=bin[poz+2]=bin[poz+3]=bin[poz+6]=1;
		break;
	case 6: // 0000101
		cout<<valoare<<'\t'<<"0000101"<<endl;
		bin[poz]=bin[poz+1]=bin[poz+2]=bin[poz+3]=bin[poz+5]=0;
		bin[poz+4]=bin[poz+6]=1;
		break;
	case 7: // 0010001
		cout<<valoare<<'\t'<<"0010001"<<endl;
		bin[poz]=bin[poz+1]=bin[poz+3]=bin[poz+4]=bin[poz+5]=0;
		bin[poz+2]=bin[poz+6]=1;
		break;
	case 8: // 0001001
		cout<<valoare<<'\t'<<"0001001"<<endl;
		bin[poz]=bin[poz+1]=bin[poz+2]=bin[poz+4]=bin[poz+5]=0;
		bin[poz+3]=bin[poz+6]=1;
		break;
	case 9: // 0010111
		cout<<valoare<<'\t'<<"0010111"<<endl;
		bin[poz]=bin[poz+1]=bin[poz+3]=0;
		bin[poz+2]=bin[poz+4]=bin[poz+5]=bin[poz+6]=1;
		break;
	}
}
void Rcode(int valoare, int bin[], int poz)
{
	switch(valoare)
	{
	case 0: // 1110010
		cout<<valoare<<'\t'<<"1110010"<<endl;
		bin[poz+3]=bin[poz+4]=bin[poz+6]=0;
		bin[poz]=bin[poz+1]=bin[poz+2]=bin[poz+5]=1;
		break;
	case 1: // 1100110
		cout<<valoare<<'\t'<<"1100110"<<endl;
		bin[poz+2]=bin[poz+3]=bin[poz+6]=0;
		bin[poz]=bin[poz+1]=bin[poz+4]=bin[poz+5]=1;
		break;
	case 2: // 1101100
		cout<<valoare<<'\t'<<"1101100"<<endl;
		bin[poz+2]=bin[poz+5]=bin[poz+6]=0;
		bin[poz]=bin[poz+1]=bin[poz+3]=bin[poz+4]=1;
		break;
	case 3: // 1000010
		cout<<valoare<<'\t'<<"1000010"<<endl;
		bin[poz+1]=bin[poz+2]=bin[poz+3]=bin[poz+4]=bin[poz+6]=0;
		bin[poz]=bin[poz+5]=1;
		break;
	case 4: // 1011100
		cout<<valoare<<'\t'<<"1011100"<<endl;
		bin[poz+1]=bin[poz+5]=bin[poz+6]=0;
		bin[poz]=bin[poz+2]=bin[poz+3]=bin[poz+4]=1;
		break;
	case 5: // 1001110
		cout<<valoare<<'\t'<<"1001110"<<endl;
		bin[poz+1]=bin[poz+2]=bin[poz+6]=0;
		bin[poz]=bin[poz+3]=bin[poz+4]=bin[poz+5]=1;
		break;
	case 6: // 1010000
		cout<<valoare<<'\t'<<"1010000"<<endl;
		bin[poz+1]=bin[poz+3]=bin[poz+4]=bin[poz+5]=bin[poz+6]=0;
		bin[poz]=bin[poz+2]=1;
		break;
	case 7: // 1000100
		cout<<valoare<<'\t'<<"1000100"<<endl;
		bin[poz+1]=bin[poz+2]=bin[poz+3]=bin[poz+5]=bin[poz+6]=0;
		bin[poz]=bin[poz+4]=1;
		break;
	case 8: // 1001000
		cout<<valoare<<'\t'<<"1001000"<<endl;
		bin[poz+1]=bin[poz+2]=bin[poz+4]=bin[poz+5]=bin[poz+6]=0;
		bin[poz]=bin[poz+3]=1;
		break;
	case 9: // 1110100
		cout<<valoare<<'\t'<<"1110100"<<endl;
		bin[poz+3]=bin[poz+5]=bin[poz+6]=0;
		bin[poz]=bin[poz+1]=bin[poz+2]=bin[poz+4]=1;
		break;
	}
}
void generare(int b[95],int nean13[13])
{
	cout<<"Cifra"<<'\t'<<"Codificare binara: "<<endl;
	cout<<5<<'\t'<<"101"<<endl; // implicit
	b[0]=b[2]=1;
	b[1]=0;
	Lcode(nean13[1],b,3);
	Gcode(nean13[2],b,10);
	Gcode(nean13[3],b,17);
	Lcode(nean13[4],b,24);
	Lcode(nean13[5],b,31);
	Gcode(nean13[6],b,38);
	b[45]=b[47]=b[49]=0;
	b[46]=b[48]=1;
	for(int i=0; i<6; i++)
		Rcode(nean13[7+i], b, 50+i*7);
	b[92]=b[94]=1;
	b[93]=0;
}
void desen(char denumire[25],int nean13[13],int b[95])
{
	fstream cod;
	cod.open("cod.html",ios::out);
	cod<<"<!DOCTYPE html>"<<endl;
	cod<<"<html>"<<endl;
	cod<<"<body>"<<endl;
	cod<<"<svg height=\"100\" width=\"200\">" << endl;
	cod<<"<text x=\"10\" y=\"20\" style=\"font-family:Verdana; font-size:24;fill:blue;\">"<<denumire;
	cod<<"</text>"<<endl;
	int pozx = 10;
	int x=0;
	for(int i=0; i<95; i++)
	{
		if((i==0)||(i==2)||(i==46)||(i==48)||(i==92)||(i==94))
		{
			cod << "<line x1=\"" << pozx << "\" y1=\"30\" x2=\"" << pozx
				<< "\" y2=\"90\" style=\"stroke:rgb(0,0,0); stroke-width:2\" />" << endl;
			pozx = pozx + 2;
			continue;
		}
		if(b[i]==1)
			cod << "<line x1=\"" << pozx << "\" y1=\"30\" x2=\"" << pozx
			<< "\" y2=\"80\" style=\"stroke:rgb(0,0,0); stroke-width:2\" />" << endl;
		pozx = pozx + 2; // Avans cu 2px, indiferent daca s-a trasat sau nu
	}
	for(int i=0;i<13;i++)
	{
		if(i==0)
		{
			cod<<"<text x=\""<<x<<"\" y=\"95\" style=\"font-family:Verdana;fill:green;\">"<<nean13[i]<<"</text>";
			x = x + 20;
			continue;
		}
		if(i==6)
		{
			cod<<"<text x=\""<<x<<"\" y=\"95\" style=\"font-family:Verdana;fill:green;\">"<<nean13[i]<<"</text>";
			x = x + 27;
			continue;
		}
		cod<<"<text x=\""<<x<<"\" y=\"95\" style=\"font-family:Verdana;fill:green;\">"<<nean13[i]<<"</text>";
		x = x + 13;
	}
	cod << "</svg>" << endl;
	cod<<"</body>"<<endl;
	cod << "</html>" << endl;
	cod.close();
}
