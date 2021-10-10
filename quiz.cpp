#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

using namespace std;
void Close(int a);
int main();
void Question1(){
    int a,b;
    system ( "cls" );
    cout<<"\t\nAn Investment in Knowledge pays the best Interest";
    cout<<"\n\tWELCOME TO THE QUIZ";
    cout<<"\n\tQuestion 1:";
    srand(time(0));
    b=(rand()%4);
    if(b==0)
    {
        cout<<"\n\tWhich gas is safe and an effective extinguisher for all confined fires?";
        cout<<"\n\t1.Nitrogen dioxide \t 2.Carbon dioxide";
        cout<<"\n\t3.Sulphur dioxide \t 4.Nitrous Oxide";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==2)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
     }
     else if(b==1){
         cout<<"\n\tWhich one of the following statements is incorrect about laser?";
        cout<<"\n\t1.It is a technique for producing intense beams of light, ultraviolet or infrared radiation of different wavelength.";
        cout<<"\n\t2.Even in diamond laser beam can drill a hole.";
        cout<<"\n\t3.A variety of lasers have been made from solids \n\tlike the ruby crystal and semi conducting materials, liquids and gases. ";
        cout<<"\n\t4.All waves in laser, travel in phase.";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==1)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
     }
     else if(b==2){
         cout<<"\n\tWhich one of the following elements the drum of a Photostat machine is made up of";
        cout<<"\n\t1.Aluminium \t 2.Selenium";
        cout<<"\n\t3.Barium \t 4.Caesium";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==2)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
     }
     else if(b==3){
         cout<<"\n\tWhich bacteria is responsible for the formation of curd?";
        cout<<"\n\t1.Lactic acid bacteria";
        cout<<"\n\t2.Lactobacillus Acidophillus";
        cout<<"\n\t3.Lactobacillus aureus";
        cout<<"\n\t4.Bacillus radicicola";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==2)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
     }
}   
void Question2(){
    int a,b;
    system ( "cls" );
    cout<<"\nQuestion 2:";
    srand(time(0));
    b=(rand()%4);
    if(b==0){
        cout<<"\n\tIn poorly ventilated buildings which one of the following inert gases can be accumulated?";
        cout<<"\n\t1.Helium\t 2.Neon";
        cout<<"\n\t3.Argon \t 4.Radon";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==4)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }
    else if(b==1){
        cout<<"\n\tHoney is sweeter than cane sugar or corn syrup. Which one\n\t of the following carbon sugars is responsible for this?";
        cout<<"\n\t1.Dextrose\t 2.Levulose";
        cout<<"\n\t3.Sucrose\t 4.Fructose";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==2)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }
    else if(b==2){
        cout<<"\n\tWhich one of the following waves are used by the common TV remote control?";
        cout<<"\n\t1.Radio waves\t 2.Lasers";
        cout<<"\n\t3.Infrared waves\t 4.Ultrasonic waves";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==3)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }
    else if(b==3){
        cout<<"\n\tTo prevent bacterial action which of the following \n\tsubstances is used in packaging of fruits?";
        cout<<"\n\t1.Ethyl bromide\t 2.Methyl bromide";
        cout<<"\n\t3.Silver bromide\t 4.Sodium bromide";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==2)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }
}
void Question3(){
    int a,b;
    system ( "cls" );
    cout<<"\nQuestion 3:";
    srand(time(0));
    b=(rand()%4);
    if(b==0){
        cout<<"\n\tRain sensors filted on the windshield wipers of some automobiles \n\tare based on which of the following principles?";
        cout<<"\n\t1.Surface tension";
        cout<<"\n\t2.Bernoulli’s principle";
        cout<<"\n\t3.Total internal reflection";
        cout<<"\n\t4.Heat radiation";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==3)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }
    else if(b==1){
        cout<<"\n\tA mule is a hybrid of which one of the following?";
        cout<<"\n\t1.A female donkey and a male horse.";
        cout<<"\n\t2.A male donkey and a female horse.";
        cout<<"\n\t3.A female horse and male zebra.";
        cout<<"\n\t4.A male horse and female zebra.";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==2)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }
    else if(b==2){
        cout<<"\n\tWhich one of the following does not \n\tbelong to Long Term Evolution (LTE) technology?";


        cout<<"\n\t1. It increases the spectral efficiency.";
        cout<<"\n\t2.It increases latency";
        cout<<"\n\t3.It reduces the cost of transmission.";
        cout<<"\n\t4.Downlink and uplink data rates are increased by it.";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==2)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }
    else if(b==3){
        cout<<"\n\tTitanium Oxide is used for which of the following purpose?";
        cout<<"\n\t1.Data Storage\t 2.Face powder";
        cout<<"\n\t3.White Paint\t 4.All of the above";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==4)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }
}
void Question4(){
    int a,b;
    system ( "cls" );
    cout<<"\nQuestion 4:";
    srand(time(0));
    b=(rand()%4);
    if(b==0){
        cout<<"\n\t Below gases and their main components are given.\n\t Select the incorrect pair among the following?";
        cout<<"\n\t1.Natural Gas – Methane";
        cout<<"\n\t2.Liquid Petroleum Gas – Butane and Isobutane";
        cout<<"\n\t3.Compressed Natural Gas – Methane";
        cout<<"\n\t4.Producer Gas – Carbon monoxide and hydrogen";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==4)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }
    else if(b==1){
        cout<<"\n\tWhich metal is used by the jewellers to make gold and platinum ornaments heavier?";
        cout<<"\n\t1.Rhodium \t 2.Iridium";
        cout<<"\n\t3.Erbium\t 4.Thorium";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==2)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }
    else if(b==2){
        cout<<"\n\tWhich one of the following gases are released from the ground,\n\t minutes or hours before an earthquake is about to strike?";
        cout<<"\n\t1.xenon \t 2.Argon";
        cout<<"\n\t3.Helium\t 4.Radon";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==4)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }
    else if(b==3){
        cout<<"\n\tWhat type of flame is produced when the oxygen supply is sufficient?";
        cout<<"\n\t1.Yellow flame     \t 2.Blue flame";
        cout<<"\n\t3.Orange flame  \t 4.None of the above ";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==2)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }
}
void Question5(){
    int a,b;
    system ( "cls" );
    cout<<"\nQuestion 5:";
    srand(time(0));
    b=(rand()%4);
    if(b==0){
        cout<<"\n\tWhich technique is used to separate the substances from a mixture?";
        cout<<"\n\t1.Chromatography     \t 2.Racing Forging";
        cout<<"\n\t3.Assembling  \t 4.All of the above ";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==1)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }if(b==1){
        cout<<"\n\tWhat is Boron?";
        cout<<"\n\t1.Non Metal    \t 2.Metal";
        cout<<"\n\t3.Metalloid  \t 4.Compound ";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==3)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }
    if(b==2){
        cout<<"\n\t Which of the following statements are correct about metals?";
        cout<<"\n\t1.Metals are lustrous.";
        cout<<"\n\t2.These are good conductors of heat and electricity.";
        cout<<"\n\t3.They can be converted into wire.";
        cout<<"\n\t4.All of these.";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==4)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }
    if(b==3){
        cout<<"\n\tA mixture of salt and sugar is known as";
        cout<<"\n\t1.Homogeneous mixture    \t 2.Heterogeneous mixture";
        cout<<"\n\t3.Mixture of Components  \t 4.None of the above ";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==2)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }
}
void Question6(){
    int a,b;
    system ( "cls" );
    cout<<"\nQuestion 6:";
    srand(time(0));
    b=(rand()%4);
    if(b==0){
        cout<<"\n\tBy which process can sea water be purified?";
        cout<<"\n\t1. Evaporation     \t 2.Fractional Distillation";
        cout<<"\n\t3.Filtration \t 4.Distillation ";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==4)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }
    if(b==1){
        cout<<"\n\tWhich technology is used to squeeze water from the soaked clothes in the washing machine?";
        cout<<"\n\t1. Evaporation     \t 2.Decantation";
        cout<<"\n\t3. Centrifugation \t 4.Sedimentation ";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==3)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }
    if(b==2){
        cout<<"\n\tDue to which process dry raisins when kept in water swell up?";
        cout<<"\n\t1.Osmosis      \t 2.Decantation";
        cout<<"\n\t3. Sedimentation \t 4.Distillation ";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==1)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }
    if(b==3){
        cout<<"\n\tBoyle's law relates to which state of matter?";
        cout<<"\n\t1. Solid state      \t 2.Liquid stage";
        cout<<"\n\t3. Gaseous state \t 4.None of the above ";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==3)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }
}
void Question7(){
    int a,b;
    system ( "cls" );
    cout<<"\nQuestion 7:" ;
    srand(time(0));
    b=(rand()%4);
    if(b==0){
        cout<<"\n\tWhich mission of NASA brought first human to moon?";
        cout<<"\n\t1.Apollo program      \t 2.Gemini Program";
        cout<<"\n\t3. Mercury Program \t 4.None of the above ";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==1)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }
    if(b==1){
        cout<<"\n\tName the first mission of NASA in which a spacecraft was reused?";
        cout<<"\n\t1.Apollo-Soyuz     \t 2.Space Shuttle";
        cout<<"\n\t3.Skylab \t 4.None of the above ";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==2)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }
    if(b==2){
        cout<<"\n\tWhat was the first manned mission of NASA?";
        cout<<"\n\t1.PQS-5    \t 2.Apollo-Soyuz";
        cout<<"\n\t3.STS-1 \t 4.Bell X-1 ";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==3)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }
    if(b==3){
        cout<<"\n\tName the first satellite which was launched specifically for the purpose of X-ray astronomy?";
        cout<<"\n\t1.Uhuru   \t 2.Hinode";
        cout<<"\n\t3.Clementine \t 4.WMAP ";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==1)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }
}
void Question8(){
    int a,b;
    system ( "cls" );
    cout<<"\nQuestion 8:" ;
    srand(time(0));
    b=(rand()%4);
    if(b==0){
        cout<<"\n\t'.MOV' extension refers usually to what kind of file?";
        cout<<"\n\t1.Image file      \t 2.Animation/movie file";
        cout<<"\n\t3. Audio file \t 4.MS Office document ";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==2)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }
    if(b==1){
        cout<<"\n\tThe purpose of choke in tube light is ?";
        cout<<"\n\t1.To decrease the current";
        cout<<"\n\t2.To increase the current";
        cout<<"\n\t3.To decrease the voltage momentarily";
        cout<<"\n\t4.To increase the voltage momentarily";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==4)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }
    if(b==2){
        cout<<"\n\tWho developed Yahoo?";
        cout<<"\n\t1.Dennis Ritchie & Ken Thompson";
        cout<<"\n\t2.David Filo & Jerry Yang";
        cout<<"\n\t3.Vint Cerf & Robert Kahn";
        cout<<"\n\t4.Steve Case & Jeff Bezos";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==2)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }
    if(b==3){
        cout<<"\n\tAfter the first photons of light are produced, which process is responsible for amplification of the light?";
        cout<<"\n\t1.Blackbody radiation\t 2.Stimulated emission";
        cout<<"\n\t3.Planck's radiation \t 4.Einstein oscillation ";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==2)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }
} 
void Question9(){
    int a,b;
    system ( "cls" );
    cout<<"\nQuestion 9:" ;
    srand(time(0));
    b=(rand()%4);
    if(b==0){
        cout<<"\n\tWho co-founded Hotmail in 1996 and then sold the company to Microsoft?";
        cout<<"\n\t1.Shawn Fanning     \t 2.Ada Byron Lovelace";
        cout<<"\n\t3. Sabeer Bhatia \t 4.Ray Tomlinson ";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==3)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }
    if(b==1){
        cout<<"\n\tWhich consists of two plates separated by a dielectric and can store a charge?";
        cout<<"\n\t1.Inductor     \t 2.Capacitor";
        cout<<"\n\t3.Transistor \t 4.Relay ";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==2)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }
    if(b==2){
         cout<<"\n\tWhat does AM mean?";
        cout<<"\n\t1.Angelo marconi     \t 2.Anno median";
        cout<<"\n\t3.Amplitude modulation \t 4.Amperes ";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==3)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }
    if(b==3){
        cout<<"\n\tWhat are three types of lasers?";
        cout<<"\n\t1.Gas, metal vapor, rock";
        cout<<"\n\t2.Pointer, diode, CD";
        cout<<"\n\t3.Diode, inverted, pointer";
        cout<<"\n\t4.Gas, solid state, diode";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==4)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }
}
void Question10(){
    int a,b;
    system ( "cls" );
    cout<<"\nQuestion 10:" ;
    srand(time(0));
    b=(rand()%4);
    if(b==0){
        cout<<"\n\tHow many bits is a byte?";
        cout<<"\n\t1.4     \t 2.8";
        cout<<"\n\t3. 16 \t 4.32 ";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==2)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }
    if(b==1){
        cout<<"\n\t	Where is the headquarters of Intel located?";
        cout<<"\n\t1.Redmond, Washington    \t 2.Tucson, Arizona";
        cout<<"\n\t3.Santa Clara, California \t 4.Richmond, Virginia";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==3)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }
    if(b==2){
         cout<<"\n\tThe letters, DOS stand for...";
        cout<<"\n\t1.Data Out System     \t 2.Disk Out System";
        cout<<"\n\t3.Disk Operating System \t 4.Data Operating System ";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==3)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }
    if(b==3){
        cout<<"\n\t	What does AC and DC stand for in the electrical field?";
        cout<<"\n\t1.Alternating Current and Direct Current";
        cout<<"\n\t2.A Rock Band from Australia";
        cout<<"\n\t3.Average Current and Discharged Capacitor";
        cout<<"\n\t4.Atlantic City and District of Columbia";
        cout<<"\n\n\tEnter your choice:";
        cin>>a;
        if(a==1)
            cout<<"\n\tCorrect Answer";
        else    
            Close(0);
    }
}


string name;
void Close(int a){
    int n;
    if(a==0){
        cout<<"\n\tYOU LOST";
        cout<<"\n\tBetter Luck Next Time"<<'\t'<<name;
    }
    else{
        cout<<"\n\tYOU WON";
        cout<<"\n\tCongrats!!"<<'\t'<<name;
        }
    cout<<"\n\tGAME OVER";
    cout<<"\n\tTHANKS FOR PLAYING";
    cout<<"\n\n\n\tMade By : \n\tJOEL JUSTIN, MOHIT ABHISHEK and KUMAR SHRIJAN";
    cout<<"\n\t 1.Play Again";
    cout<<"\n\t 2.Exit";
    cin>>n;
    if(n==2)
        exit(0);
    else
        main();    
         
    }
int main()
{   system ( "cls" );
    
    cout<<"\n\tEnter your name:";
    cin>>name;
    Question1();
    Question2();
    Question3();
    Question4();
    Question5();
    Question6();
    Question7();
    Question8();
    Question9();
    Question10();
    

    Close(1);
    return 0;

}    
