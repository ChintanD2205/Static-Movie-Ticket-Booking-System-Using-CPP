#include<iostream>
#include<string.h>
#include<conio.h>
#include<windows.h>
#define MID 1234 //To define the manager id
#define MP 2208 //To define manager password
#define sleeptime 500
#define sleeptimeT 300
using namespace std;

class TicketBooking
{
    private:
        int user_id, user_password, manager_id, manager_password, A;
        char manager_decision[100];
        char name[1000];
        string s[100][100];
        int ns;
    public:
        void log_in_user(); //If a registered user comes along
        void sign_up_user(); // to signup a new user
        void if_manager();      //For checking if the person is a manager or not
        void theatre_decide(); // names of theatre
        void current_showtimings(); //Predecided show timings
        int calculate_total(int customer_choice_seat_type, int nt);
        void num_show();
        void manager_decision1();
        void manager_decision_show();
};

class DisplayTheatre
{
    private :
    public:
        void seat_display();
        void display_seat_type();
        void theatre_info(int customer_choice_movie, int customer_choice_time_slot, int customer_choice_seat_type, int customer_choice_movie_theatre, string customer_choice_language, string customer_choice_mode);
        void ticket_display(int nt, int customer_choice_movie, int customer_choice_time_slot, int customer_choice_seat_type, int customer_choice_movie_theatre, char customer_choice_seat_row, int customer_choice_seat_number[], string customer_choice_language, string customer_choice_mode);
};

class DifferentActivity : public TicketBooking, public DisplayTheatre
{
    public:
        int f[100], b[100], bp, food_items_number, np, npa, ngb, ns, nf, nn, num_beverages, num_soft_drink, num_milk_drink, num_water, total_bill;
        int choice_bucket_popcorn[100], choice_bucket_size[100];
        int choice_pizza[100], choice_pizza_size[100];
        int choice_fries[100], choice_fries_size[100];
        int choice_soft_drink[100];
        int choice_milk_drink[100];
        void food_beverage();
        void bill_display(int nt, int customer_choice_movie, int customer_choice_time_slot, int customer_choice_seat_type, int customer_choice_movie_theatre, char customer_choice_seat_row, int customer_choice_seat_number[100], string customer_choice_language, string customer_choice_mode, int f[100], int b[100], int bp, int food_items_number, int np, int npa, int ngb, int ns, int nf, int nn, int num_beverages, int num_soft_drink, int num_milk_drink, int choice_bucket_popcorn[100], int choice_bucket_size[100], int choice_pizza[100], int choice_pizza_size[100], int choice_fries[100], int choice_fries_size[100], int choice_soft_drink[100], int choice_milk_drink[100]);
};
void TicketBooking :: log_in_user()
{
    //here only scanning of log in id and password takes place
    cout<<endl;
    cout<<"\t\t\t*****CD*****"<<endl;
    cout<<"\t\t\tUser ID : ";
    cin>>user_id;
    cout<<"\t\t\tPassword : ";
    cin>>user_password;
}

void TicketBooking :: sign_up_user()
{
    //here new user log in id and password takes place
    cout<<"\t\t\t*****CD*****"<<endl;
    cout<<"\t\t\tEnter Name : ";
    cin>>name;
    cout<<"\t\t\tUser ID : ";
    cin>>user_id;
    cout<<"\t\t\tPassword : ";
    cin>>user_password;
    cout<<"\t\t\tWelcome "<<name<<endl;
}

void TicketBooking :: if_manager()
{
    /* This function checks if the person is manager or not.
        it is an incredible function*/
    int i=0;
    pass:
        {
    cout<<"*****CD*****"<<endl;
    cout<<"Manager ID : ";
    cin>>manager_id;
    cout<<"Password : ";
    cin>>manager_password;
    cout<<endl<<endl;
    if(manager_id==MID && manager_password==MP)
    {
        cout<<"Welcome!!"<<endl;
    }
    else
    {
        cout<<endl;
        do{
            cout<<"Invalid Credentials"<<endl;
            i++;
            cout<<i;
            cout<<endl<<endl;
            if(i==3)
            {
                cout<<"GET LOST"<<endl;
                break;
            }
            goto pass;
        }while(i<3);
    }}
}

void TicketBooking :: current_showtimings()
{
    //Predecided Show timings
    cout<<"\t\t\t1. Doctor Strange: In The Multiverse of Madness"<<endl<<endl;
    cout<<"\t\t\t\tEnglish | Hindi | Tamil"<<endl;
    cout<<"\t\t\t\t 3D | 2D | 3DX | 4D"<<endl;
    cout<<"\t\t\t\t\t 10:00 |/\| 11:00 |/\| 15:00 |/\| 17:30 |/\| 18:00 |/\| 21:00 |/\| 23:00"<<endl<<endl;
    cout<<"\t\t\t2. KGF : Chapter 2"<<endl;
    cout<<"\t\t\t\tEnglish | Hindi | Tamil"<<endl;
    cout<<"\t\t\t\t\t 10:30 |/\| 12:00 |/\| 13:00 |/\| 18:00 |/\| 21:00 |/\| 23:00"<<endl<<endl;
    cout<<"\t\t\t3. Runway 34"<<endl;
    cout<<"\t\t\t\tEnglish | Hindi "<<endl;
    cout<<"\t\t\t\t 3D | 2D "<<endl;
    cout<<"\t\t\t\t\t 10:00 |/\| 11:00 |/\| 21:00 |/\| 23:00"<<endl<<endl;
    cout<<"\t\t\t4. RRR"<<endl;
    cout<<"\t\t\t\tEnglish | Hindi | Tamil"<<endl;
    cout<<"\t\t\t\t 3D | 2D | 3DX | 4D"<<endl;
    cout<<"\t\t\t\t\t 10:30 |/\| 12:00 |/\| 14:00 |/\| 20:00 |/\| 21:00 |/\| 23:00"<<endl<<endl;
    cout<<"\t\t\t5. Gangubai Kathiawadi"<<endl;
    cout<<"\t\t\t\tEnglish | Hindi "<<endl;
    cout<<"\t\t\t\t\t 10:00 |/\| 11:00 |/\| 15:00 |/\| 18:00 |/\| 21:00 |/\| 23:00"<<endl<<endl;
}

void TicketBooking :: manager_decision1()
{
    int i=0, j=0;
                    cout<<endl<<"\t\tEnter no. of shows for whom you wanna enter data : ";
                    cin>>ns;
                    for(i=0;i<ns;i++)
                    {
                        cout<<"\t\t\tData "<<i+1<<endl;
                        for(j=0;j<5;j++)
                        {
                            if(j==0)
                            {
                                cout<<"\t\t\t\tEnter serial number : ";
                                cin>>s[i][j];
                                cout<<endl<<endl;
                            }
                            else if(j==1)
                            {
                                cout<<"\t\t\t\tEnter movie name : ";
                                cin>>s[i][j];
                                cout<<endl<<endl;
                            }
                            else if(j==2)
                            {
                                cout<<"\t\t\t\tEnter languages : ";
                                cin>>s[i][j];
                                cout<<endl<<endl;
                            }
                            else if(j==3)
                            {
                                cout<<"\t\t\t\tEnter type of view : ";
                                cin>>s[i][j];
                                cout<<endl<<endl;
                            }
                            else if(j==4)
                            {
                                cout<<"\t\t\t\tEnter time slots : ";
                                cin>>s[i][j];
                                cout<<endl<<endl;
                            }
                        }
                    }
}

void TicketBooking :: manager_decision_show()
{
    int i=0, j=0;
    for(i=0;i<ns;i++)
    {
        for(j=0;j<5;j++)
        {
            if(j==0)
            {
                cout<<"\t\t\t"<<s[i][j]<<". ";
            }
            else if(j==1)
            {
                cout<<s[i][j];
                cout<<endl;
            }
            else if(j==2)
            {
                cout<<"\t\t\t\t"<<s[i][j];
                cout<<endl;
            }
            else if(j==3)
            {
                cout<<"\t\t\t\t "<<s[i][j];
                cout<<endl;
            }
            else if(j==4)
            {
                cout<<"\t\t\t\t\t "<<s[i][j];
                cout<<endl;
            }
        }
    }
}

int TicketBooking :: calculate_total(int customer_choice_seat_type, int nt)
{
    if(customer_choice_seat_type==1)
    {
        return (nt*70);
    }
    if(customer_choice_seat_type==2)
    {
        return (nt*120);
    }
    if(customer_choice_seat_type==3)
    {
        return (nt*220);
    }
    if(customer_choice_seat_type==4)
    {
        return (nt*500);
    }
}

void DifferentActivity :: bill_display(int nt, int customer_choice_movie, int customer_choice_time_slot, int customer_choice_seat_type, int customer_choice_movie_theatre, char customer_choice_seat_row, int customer_choice_seat_number[], string customer_choice_language, string customer_choice_mode, int f[], int b[], int bp, int food_items_number, int np, int npa, int ngb, int ns, int nf, int nn, int num_beverages, int num_soft_drink, int num_milk_drink, int choice_bucket_popcorn[], int choice_bucket_size[], int choice_pizza[], int choice_pizza_size[], int choice_fries[], int choice_fries_size[], int choice_soft_drink[], int choice_milk_drink[])
{
    int i,j;
    cout<<"\t\t\t\t\t ___________________________________"<<endl;
    Sleep(sleeptime);
    cout<<"\t\t\t\t\t|\t\t CODM       \t    |"<<endl;
                if(customer_choice_movie_theatre==1)
                {
                    cout<<"\t\t\t\t\t|\t\tMETRO INOX\t    |"<<endl;
                }
                else if(customer_choice_movie_theatre==2)
                {
                    cout<<"\t\t\t\t\t|\t    MUKTA A2 SUNCITY\t    |"<<endl;
                }
                else if(customer_choice_movie_theatre==3)
                {
                    cout<<"\t\t\t\t\t|\t    STERLING CINEPLEX       |"<<endl;;
                }
                else if(customer_choice_movie_theatre==4)
                {
                    cout<<"\t\t\t\t\t|\t    LIBERTY CINEMAS         |"<<endl;
                }
                else if(customer_choice_movie_theatre==5)
                {
                    cout<<"\t\t\t\t\t|\t    IHRJVC  CINEMAS         |"<<endl;
                }

                if(customer_choice_movie==1)
                {
                    cout<<"\t\t\t\t\t|\tDoctor Strange : In The\t    |\n\t\t\t\t\t|     Multiverse of Madness : "<<customer_choice_time_slot<<"  | "<<endl;
                }
                else if(customer_choice_movie==2)
                {
                    cout<<"\t\t\t\t\t|\tKGF : Chapter 2 : "<<customer_choice_time_slot<<"\t    | "<<endl;
                }
                else if(customer_choice_movie==3)
                {
                    cout<<"\t\t\t\t\t|\t     Runway 34 : "<<customer_choice_time_slot<<"\t    |"<<endl;
                }
                else if(customer_choice_movie==4)
                {
                    cout<<"\t\t\t\t\t|\t       RRR : "<<customer_choice_time_slot<<"\t    | "<<endl;
                }
                else if(customer_choice_movie==5)
                {
                    cout<<"\t\t\t\t\t|\tGangubai Kathiawadi : "<<customer_choice_time_slot<<"  | "<<endl;
                }

                if(customer_choice_seat_type==1)
                {
                    cout<<"\t\t\t\t\t|\t     STALL -- $70\t    |"<<endl;
                }
                else if(customer_choice_seat_type==2)
                {
                    cout<<"\t\t\t\t\t|\t     BALCONY -- $120\t    |"<<endl;
                }
                else if(customer_choice_seat_type==3)
                {
                    cout<<"\t\t\t\t\t|\t     RECLINER -- $220\t    |"<<endl;
                }
                else if(customer_choice_seat_type==4)
                {
                    cout<<"\t\t\t\t\t|\tLUXURY DELUXE -- $500\t    |"<<endl;
                }
    Sleep(sleeptime);
    if(customer_choice_seat_type==1)
    {
        if(nt==1)
        {
            cout<<"\t\t\t\t\t| TICKETS X "<<nt<<"\t\t        $"<<(70*nt)<<" |"<<endl;
        }
        else
        {
            cout<<"\t\t\t\t\t| TICKETS X "<<nt<<"\t\t       $"<<(70*nt)<<" |"<<endl;
        }
        total_bill += (70*nt);
    }
    else if(customer_choice_seat_type==2)
    {
        cout<<"\t\t\t\t\t| TICKETS X "<<nt<<"\t\t       $"<<(120*nt)<<" |"<<endl;
        total_bill += (120*nt);
    }
    else if(customer_choice_seat_type==3)
    {
        cout<<"\t\t\t\t\t| TICKETS X "<<nt<<"\t\t       $"<<(220*nt)<<" |"<<endl;
        total_bill += (220*nt);
    }
    else if(customer_choice_seat_type==4)
    {
        if(nt==1)
        {
            cout<<"\t\t\t\t\t| TICKETS X "<<nt<<"\t\t       $"<<(500*nt)<<" |"<<endl;
        }
        else
        {
            cout<<"\t\t\t\t\t| TICKETS X "<<nt<<"\t\t      $"<<(500*nt)<<" |"<<endl;
        }
        total_bill += (500*nt);
    }
    Sleep(sleeptime);

    for(i=0;i<food_items_number;i++)
    {
        if(f[i]==1)
        {
            for(j=0;j<bp;j++)
                    {
                        if(choice_bucket_popcorn[j]==1)
                        {
                            if(choice_bucket_size[j]==1)
                            {
                                cout<<"\t\t\t\t\t| Normal Popcorn | Small | \t$20 |"<<endl;
                                total_bill += 20 ;
                                Sleep(sleeptimeT);
                            }
                            else if(choice_bucket_size[j]==2)
                            {
                                cout<<"\t\t\t\t\t| Normal Popcorn | Large | \t$30 |"<<endl;
                                total_bill += 30 ;
                                Sleep(sleeptimeT);
                            }
                        }
                        else if(choice_bucket_popcorn[j]==2)
                        {
                            if(choice_bucket_size[j]==1)
                            {
                                cout<<"\t\t\t\t\t| Butter Popcorn | Small | \t$40 |"<<endl;
                                total_bill += 40 ;
                                Sleep(sleeptimeT);
                            }
                            else if(choice_bucket_size[j]==2)
                            {
                                cout<<"\t\t\t\t\t| Butter Popcorn | Large | \t$70 |"<<endl;
                                total_bill += 70 ;
                                Sleep(sleeptimeT);
                            }
                        }
                        else if(choice_bucket_popcorn[j]==1)
                        {
                            if(choice_bucket_size[j]==1)
                            {
                                cout<<"\t\t\t\t\t| Cheese Popcorn | Small | \t$80 |"<<endl;
                                total_bill += 80 ;
                                Sleep(sleeptimeT);
                            }
                            else if(choice_bucket_size[j]==2)
                            {
                                cout<<"\t\t\t\t\t| Cheese Popcorn | Large | \t$150 |"<<endl;
                                total_bill += 150 ;
                                Sleep(sleeptimeT);
                            }
                        }
                        else if(choice_bucket_popcorn[j]==1)
                        {
                            if(choice_bucket_size[j]==1)
                            {
                                cout<<"\t\t\t\t\t| Ch&But Popcorn | Small | \t$120 |"<<endl;
                                total_bill += 120 ;
                                Sleep(sleeptimeT);
                            }
                            else if(choice_bucket_size[j]==2)
                            {
                                cout<<"\t\t\t\t\t| Ch&But Popcorn | Large | \t$230 |"<<endl;
                                total_bill += 230 ;
                                Sleep(sleeptimeT);
                            }
                        }
                    }

        }

        else if(f[i]==2)
        {
            for(j=0;j<np;j++)
            {
                if(choice_pizza[j] == 1)
                {
                    if(choice_pizza_size[j] == 1)
                    {
                        cout<<"\t\t\t\t\t| Veggie Cheese - 08'' \t\t$90 |"<<endl;
                        total_bill += 90 ;
                        Sleep(sleeptimeT);
                    }
                    else if(choice_pizza_size[j] == 2)
                    {
                        cout<<"\t\t\t\t\t| Veggie Cheese - 10'' \t       $150 |"<<endl;
                        total_bill += 150 ;
                        Sleep(sleeptimeT);
                    }
                    else if(choice_pizza_size[j] == 3)
                    {
                        cout<<"\t\t\t\t\t| Veggie Cheese - 12'' \t       $200 |"<<endl;
                        total_bill += 200 ;
                        Sleep(sleeptimeT);
                    }
                }
                else if(choice_pizza[j] == 2)
                {
                    if(choice_pizza_size[j] == 1)
                    {
                        cout<<"\t\t\t\t\t| Italiano Mania - 08'' \t$95 |"<<endl;
                        total_bill += 95 ;
                        Sleep(sleeptimeT);
                    }
                    else if(choice_pizza_size[j] == 2)
                    {
                        cout<<"\t\t\t\t\t| Italiano Mania - 10''        $170 |"<<endl;
                        total_bill += 170 ;
                        Sleep(sleeptimeT);
                    }
                    else if(choice_pizza_size[j] == 3)
                    {
                        cout<<"\t\t\t\t\t| Italiano Mania - 12''        $230 |"<<endl;
                        total_bill += 230 ;
                        Sleep(sleeptimeT);
                    }
                }
                else if(choice_pizza[j] == 3)
                {
                    if(choice_pizza_size[j] == 1)
                    {
                        cout<<"\t\t\t\t\t| Cheese Paneer - 08'' \t\t$80 |"<<endl;
                        total_bill += 80 ;
                        Sleep(sleeptimeT);
                    }
                    else if(choice_pizza_size[j] == 2)
                    {
                        cout<<"\t\t\t\t\t| Cheese Paneer - 10'' \t       $180 |"<<endl;
                        total_bill += 180 ;
                        Sleep(sleeptimeT);
                    }
                    else if(choice_pizza_size[j] == 3)
                    {
                        cout<<"\t\t\t\t\t| Cheese Paneer - 12'' \t       $270 |"<<endl;
                        total_bill += 270 ;
                        Sleep(sleeptimeT);
                    }
                }
                else if(choice_pizza[j] == 4)
                {
                    if(choice_pizza_size[j] == 1)
                    {
                        cout<<"\t\t\t\t\t| Corn and Onion - 08'' \t$85 |"<<endl;
                        total_bill += 85 ;
                        Sleep(sleeptimeT);
                    }
                    else if(choice_pizza_size[j] == 2)
                    {
                        cout<<"\t\t\t\t\t| Corn and Onion - 10''        $130 |"<<endl;
                        total_bill += 130 ;
                        Sleep(sleeptimeT);
                    }
                    else if(choice_pizza_size[j] == 3)
                    {
                        cout<<"\t\t\t\t\t| Corn and Onion - 12''        $190 |"<<endl;
                        total_bill += 190 ;
                        Sleep(sleeptimeT);
                    }
                }
            }
        }
        else if(f[i]==3)
        {
            if(ns<=6)
            {
                cout<<"\t\t\t\t\t| Samosa X "<<ns<<"\t\t        $"<<(15*ns)<<" |"<<endl;
            }
            else
            {
                cout<<"\t\t\t\t\t| Samosa X "<<ns<<"\t\t       $"<<(15*ns)<<" |"<<endl;
            }
            total_bill += (15*ns) ;
            Sleep(sleeptimeT);
        }
        else if(f[i]==4)
        {
            for(j=0;j<nf;j++)
            {
                if(choice_fries[j] == 1)
                {
                    if(choice_fries_size[j] == 1)
                    {
                        cout<<"\t\t\t\t\t| Salted Fries - Small\t        $80 |"<<endl;
                        total_bill += 80 ;
                        Sleep(sleeptimeT);
                    }
                    else if(choice_fries_size[j] == 2)
                    {
                        cout<<"\t\t\t\t\t| Salted Fries - Medium\t        $90 |"<<endl;
                        total_bill += 90 ;
                        Sleep(sleeptimeT);
                    }
                    else if(choice_fries_size[j] == 3)
                    {
                        cout<<"\t\t\t\t\t| Salted Fries - Large\t       $110 |"<<endl;
                        total_bill += 110 ;
                        Sleep(sleeptimeT);
                    }
                }
                else if(choice_fries[j] == 2)
                {
                    if(choice_fries_size[j] == 1)
                    {
                        cout<<"\t\t\t\t\t| Cheese Fries - Small\t        $90 |"<<endl;
                        total_bill += 90 ;
                        Sleep(sleeptimeT);
                    }
                    else if(choice_fries_size[j] == 2)
                    {
                        cout<<"\t\t\t\t\t| Cheese Fries - Medium\t       $120 |"<<endl;
                        total_bill += 120 ;
                        Sleep(sleeptimeT);
                    }
                    else if(choice_fries_size[j] == 3)
                    {
                        cout<<"\t\t\t\t\t| Cheese Fries - Large\t       $140 |"<<endl;
                        total_bill += 140 ;
                        Sleep(sleeptimeT);
                    }
                }
                else if(choice_fries[j] == 3)
                {
                    if(choice_fries_size[j] == 1)
                    {
                        cout<<"\t\t\t\t\t| Jalapeno Fries - Small       $100 |"<<endl;
                        total_bill += 100 ;
                        Sleep(sleeptimeT);
                    }
                    else if(choice_fries_size[j] == 2)
                    {
                        cout<<"\t\t\t\t\t| Jalapeno Fries - Medium      $130 |"<<endl;
                        total_bill += 130 ;
                        Sleep(sleeptimeT);
                    }
                    else if(choice_fries_size[j] == 3)
                    {
                        cout<<"\t\t\t\t\t| Jalapeno Fries - Large       $150 |"<<endl;
                        total_bill += 150 ;
                        Sleep(sleeptimeT);
                    }
                }
            }
        }
    }
    for(i=0;i<num_beverages;i++)
    {
        if(b[i]==1)
        {
           for(j=0;j<num_soft_drink;j++)
            {
                if(choice_soft_drink[j]==1)
                {
                    cout<<"\t\t\t\t\t| Pepsi \t\t\t$80 |"<<endl;
                    total_bill += 80 ;
                    Sleep(sleeptimeT);
                }
                else if(choice_soft_drink[j]==2)
                {
                    cout<<"\t\t\t\t\t| Sprite \t\t\t$80 |"<<endl;
                    total_bill += 80 ;
                    Sleep(sleeptimeT);
                }
                else if(choice_soft_drink[j]==3)
                {
                    cout<<"\t\t\t\t\t| Coca Cola \t\t\t$80 |"<<endl;
                    total_bill += 80 ;
                    Sleep(sleeptimeT);
                }
            }
        }
        else if(b[i]==2)
        {
           for(j=0;j<num_milk_drink;j++)
            {
                if(choice_milk_drink[j]==1)
                {
                    cout<<"\t\t\t\t\t| Chocolate Shake \t\t$80 |"<<endl;
                    total_bill += 80 ;
                    Sleep(sleeptimeT);
                }
                else if(choice_milk_drink[j]==2)
                {
                    cout<<"\t\t\t\t\t| Oreo Shake \t\t\t$80 |"<<endl;
                    total_bill += 80 ;
                    Sleep(sleeptimeT);
                }
                else if(choice_milk_drink[j]==3)
                {
                    cout<<"\t\t\t\t\t| Mango Shake \t\t\t$80 |"<<endl;
                    total_bill += 80 ;
                    Sleep(sleeptimeT);
                }
            }
        }
        else if(b[i]==3)
        {
            cout<<"\t\t\t\t\t| Water X "<<num_water<<"\t\t\t$"<<num_water*30<<" |"<<endl;
            total_bill += (num_water*30) ;
            Sleep(sleeptimeT);
        }

    }

    cout<<"\t\t\t\t\t|-----------------------------------|"<<endl;
    if(total_bill>99 && total_bill<999)
    {
        cout<<"\t\t\t\t\t| TOTAL \t\t       $"<<total_bill<<" | "<<endl;
    }
    else if(total_bill>999 && total_bill<9999)
    {
        cout<<"\t\t\t\t\t| TOTAL \t\t      $"<<total_bill<<" | "<<endl;
    }
    else if(total_bill>9999 && total_bill<99999)
    {
        cout<<"\t\t\t\t\t| TOTAL \t\t     $"<<total_bill<<" | "<<endl;
    }
    else if(total_bill>99999)
    {
        cout<<"\t\t\t\t\t| TOTAL \t\t    $"<<total_bill<<" | "<<endl;
    }
    else
    {
        cout<<"\t\t\t\t\t| TOTAL  \t\t\t$"<<total_bill<<" | "<<endl;
    }
    cout<<"\t\t\t\t\t'___________________________________'"<<endl;
}

void DifferentActivity :: food_beverage()
{
    int i;
    food:
    {
        cout<<"\t -------FOOD-------"<<endl;
        cout<<"\t 1. Popcorn "<<endl;
        cout<<"\t 2. Pizza "<<endl;
        cout<<"\t 3. Samosa -- $14.50"<<endl;
        cout<<"\t 4. Fries "<<endl;
        cout<<endl<<endl<<endl;
        cout<<"\t -------BEVERAGES-------"<<endl;
        cout<<"\t 1. SoftDrinks"<<endl;
        cout<<"\t 2. Milk Drinks"<<endl;
        cout<<"\t 3. Water"<<endl;
        cout<<endl<<endl;

        cout<<"\t\t\tEnter number of food items you wish to order : ";
        cin>>food_items_number;
        cout<<endl<<endl;

        for(i=0;i<food_items_number;i++)
        {
            cout<<"\t Enter Respective Serial Number Of Your Choice For Food : ";
            cin>>f[i];

            switch(f[i])
            {
                case 1:
                {
                    cout<<"\t\t -------POPCORN-------"<<endl;
                    cout<<"\t\t 1. Normal Popcorn    -- $20 / $30"<<endl;
                    cout<<"\t\t 2. Butter Popcorn    -- $40 / $70"<<endl;
                    cout<<"\t\t 3. Cheese Popcorn    -- $80 / $150"<<endl;
                    cout<<"\t\t 4. Ch&But Popcorn    -- $120 / $230"<<endl;

                    cout<<"\t\t How Many Buckets Do You Want ?  ";
                    cin>>bp;
                    int j;
                    for(j=0;j<bp;j++)
                    {
                        cout<<"\t\tBUCKET "<<j+1<<endl;
                        cout<<"\t\t\t Enter Your Choice Of Popcorn "<<j+1<<" : ";
                        cin>>choice_bucket_popcorn[j];
                        cout<<"\t\t\t 1. Small \n\t\t\t 2. Large ==> ";
                        cin>>choice_bucket_size[j];
                    }
                    break;
                }

                case 2:
                {
                    cout<<"\t\t -------PIZZA---------8''----10''---12''-"<<endl;
                    cout<<"\t\t 1. Veggie Cheese  -- $90  | $150 | $200"<<endl;
                    cout<<"\t\t 2. Italiano Mania -- $95  | $170 | $230"<<endl;
                    cout<<"\t\t 3. Cheese Paneer  -- $80  | $180 | $270"<<endl;
                    cout<<"\t\t 4. Corn and Onion -- $85  | $130 | $190"<<endl;

                    cout<<"\t\t How Many Pizzas Do You Want ?  ";
                    cin>>np;
                    int j;
                    for(j=0;j<np;j++)
                    {
                        cout<<"\t\tPIZZA "<<j+1<<endl;
                        cout<<"\n\t\t\t Enter Your Choice Of Pizza "<<j+1<<" : ";
                        cin>>choice_pizza[j];
                        cout<<"\t\t\t 1. 8'' or 2. 10'' or 3. 12'' ==> ";
                        cin>>choice_pizza_size[j];
                    }
                    break;
                }

                case 3:
                {
                    cout<<"\n\t\t How Many Plates(per 2) Do You Want ?  ";
                    cin>>ns;
                    break;
                }

                case 4:
                {
                    cout<<"\n\t\t -------FRIES--------Small--Medium-Large-"<<endl;
                    cout<<"\t\t 1. Salted         -- $80  | $90  | $110"<<endl;
                    cout<<"\t\t 2. Cheese         -- $90  | $120 | $140"<<endl;
                    cout<<"\t\t 3. Jalapeno       -- $100 | $130 | $150"<<endl;

                    cout<<"\t\t How Many Buckets Do You Want ?  ";
                    cin>>nf;
                    int j;
                    for(j=0;j<nf;j++)
                    {
                        cout<<"\t\t FRIES "<<j+1<<endl;
                        cout<<"\n\t\t\t Enter Your Choice Of Fries "<<j+1<<" : ";
                        cin>>choice_fries[j];
                        cout<<"\t\t\t 1. Small \n\t\t\t 2. Medium \n\t\t\t 3. Large ==> ";
                        cin>>choice_fries_size[j];
                    }
                    break;
                }

                default:
                {
                    do
                    {
                        cout<<"Invalid Credentials !!"<<endl;
                        goto food;
                        i++;
                    }while(i<3);
                }
            }
        }

        beverage :
        {
            cout<<endl<<endl<<endl;
            cout<<"\t -------BEVERAGES-------"<<endl;
            cout<<"\t 1. SoftDrinks"<<endl;
            cout<<"\t 2. Milk Drinks"<<endl;
            cout<<"\t 3. Water"<<endl;
            cout<<endl<<endl;

            cout<<"Enter Number of Beverages you would like to order : ";
            cin>>num_beverages;

            for(i=0;i<num_beverages;i++)
            {
                cout<<"\t Enter Your Choice For Beverage : ";
                cin>>b[i];

                switch(b[i])
                {
                    case 1:
                    {
                        cout<<"\t\t ------SOFT-DRINKS------"<<endl;
                        cout<<"\t\t All 1L"<<endl;
                        cout<<"\t\t 1. Pepsi     -- $80"<<endl;
                        cout<<"\t\t 2. Sprite    -- $80"<<endl;
                        cout<<"\t\t 3. Coca Cola -- $80"<<endl;
                        cout<<endl<<endl;

                        cout<<"\t\t How Many Soft Drinks Would You Like To Order : ";
                        cin>>num_soft_drink;

                        int j;

                        for(j=0;j<num_soft_drink;j++)
                        {
                            cout<<"\t\t\t DRINK "<<j+1<<" : ";
                            cin>>choice_soft_drink[j];
                        }
                        break;
                    }
                    case 2:
                    {
                        cout<<"\t\t ------MILK-DRINKS------"<<endl;
                        cout<<"\t\t All 1L"<<endl;
                        cout<<"\t\t 1. Chocolate Shake -- $80"<<endl;
                        cout<<"\t\t 2. Oreo Shake      -- $80"<<endl;
                        cout<<"\t\t 3. Mango Shake     -- $80"<<endl;
                        cout<<endl<<endl;

                        cout<<"\t\t How Many Milk Drinks Would You Like To Order : ";
                        cin>>num_milk_drink;

                        int j;

                        for(j=0;j<num_milk_drink;j++)
                        {
                            cout<<"\t\t\t DRINK "<<j+1<<" : ";
                            cin>>choice_milk_drink[j];
                        }
                        break;
                    }
                    case 3:
                    {
                        cout<<"\t\t\t Water -- $30"<<endl;

                        cout<<"\t\t\t\t Enter number of water bottles you would like to purchase : ";
                        cin>>num_water;
                        break;
                    }
                    default:
                    {
                        do
                        {
                            cout<<"INVALID CREDENTIALS"<<endl;
                            i++;
                            goto beverage;
                        }while(i<3);
                        break;
                    }
                }
            }
        }
    }
}

void name()
{
    int i;

    for(i=-22;i<48;i++)
    {
            cout<<"$$$";
    }
    cout<<"\n";
    for(i=-22;i<48;i++)
    {
            cout<<"$$$";
    }
    cout<<"\n";
    for(i=-22;i<48;i++)
    {
        if(i==3||i==4||i==5||i==7||i==8||i==9||i==11||i==12||i==13||i==14||i==17||i==21)
        {
            cout<<"   ";
        }
        else
        {
            cout<<"$$$";
        }
    }
    cout<<"\n";
    for(i=-22;i<48;i++)
    {
        if(i==3||i==7||i==9||i==11||i==15||i==17||i==18||i==20||i==21)
        {
            cout<<"   ";
        }
        else
        {
            cout<<"$$$";
        }
    }
    cout<<"\n";
    for(i=-22;i<48;i++)
    {
        if(i==3||i==7||i==9||i==11||i==15||i==17||i==19||i==21)
        {
            cout<<"   ";
        }
        else
        {
            cout<<"$$$";
        }
    }
    cout<<"\n";
    for(i=-22;i<48;i++)
    {
        if(i==3||i==7||i==9||i==11||i==15||i==17||i==21)
        {
            cout<<"   ";
        }
        else
        {
            cout<<"$$$";
        }
    }
    cout<<"\n";
    for(i=-22;i<48;i++)
    {
        if(i==3||i==4||i==5||i==7||i==8||i==9||i==11||i==12||i==13||i==14||i==17||i==21)
        {
            cout<<"   ";
        }
        else
        {
            cout<<"$$$";
        }
    }
    cout<<"\n";
    for(i=-22;i<48;i++)
    {
            cout<<"$$$";
    }
    cout<<"\n";
    for(i=-22;i<48;i++)
    {
            cout<<"$$$";
    }
    cout<<"\n";
}

void DisplayTheatre :: seat_display()
{
    int i,j;
    cout<<endl;
    cout<<" ____LUXURY_DELUXE_$500___";
    for(i=0;i<35;i++)
    {
        if(i>5)
        {
            cout<<"______";
        }
    }
    cout<<endl;
    for(j=0;j<12;j++)
    {
        for(i=0;i<=11;i++)
        {
            if(j==0)
            {
                if(i==0)
                {
                    cout<<"\t\tA";
                }
                else if(i==2||i==4||i==6||i==8||i==10)
                {
                    cout<<"             ";
                }
                else
                {
                    cout<<" [------A"<<i<<"------] ";
                }
            }

            if(j==1)
            {
                if(i==0)
                {
                    cout<<endl;
                    cout<<"\t\tB";
                }
                else if(i==1||i==3||i==5||i==7||i==9||i==11)
                {
                    cout<<"               ";
                }
                else if(i==4||i==6||i==8||i==10)
                {
                    cout<<"[------B"<<i<<"-----] ";
                }
                else
                {
                    cout<<"  [------B"<<i<<"-----] ";
                }
            }
        }
    }
    cout<<endl;
    cout<<" ____RECLINER_$220";
    for(i=0;i<36;i++)
    {
        if(i>5)
        {
            cout<<"______";
        }
    }
    cout<<endl;
    for(j=0;j<12;j++)
    {
        for(i=0;i<27;i++)
        {
            if(j==2)
            {
                if(i==0)
                {
                    cout<<"\t\tC";
                }
                if(i==3||i==4||i==7||i==8)
                {
                    cout<<"      ";
                }
                else if(i==11||i==12||i==15||i==16||i==19||i==20||i==23||i==24||i==27)
                {
                    cout<<"       ";
                }
                else{
                    cout<<" [C"<<i+1<<"] ";
                }
            }

            if(j==3)
            {
                if(i==0)
                {
                    cout<<endl;
                    cout<<"\t\tD";
                }
                if(i==1||i==2||i==5||i==6||i==9)
                {
                    cout<<"      ";
                }
                else if(i==13||i==14||i==17||i==18||i==21||i==22||i==25||i==26)
                {
                    cout<<"       ";
                }
                else if(i==10)
                {
                    cout<<"        ";
                }
                else{
                    cout<<" [D"<<i+1<<"] ";
                }
            }
            if(j==4)
            {
                if(i==0)
                {
                    cout<<endl;
                    cout<<"\t\tE";
                }
                if(i==3||i==4||i==7||i==8)
                {
                    cout<<"      ";
                }
                else if(i==11||i==12||i==15||i==16||i==19||i==20||i==23||i==24||i==27)
                {
                    cout<<"       ";
                }
                else{
                    cout<<" [E"<<i+1<<"] ";
                }
            }
        }
    }
    cout<<endl;
    cout<<" ____BALCONY_$120";
    for(i=0;i<36;i++)
    {
        if(i>5)
        {
            cout<<"______";
        }
    }
    cout<<endl;
    for(j=0;j<12;j++)
    {
        for(i=0;i<27;i++)
        {
            if(j==5)
            {
                if(i==0)
                {
                    cout<<"\t\tF";
                }
                if(i==5)
                {
                    cout<<"      ";
                }
                else if(i==13||i==15||i==23)
                {
                    cout<<"       ";
                }
                else{
                    cout<<" [F"<<i+1<<"] ";
                }
            }
            if(j==6)
            {
                if(i==0)
                {
                    cout<<endl;
                    cout<<"\t\tG";
                }
                if(i==5)
                {
                    cout<<"      ";
                }
                else if(i==13||i==15||i==23)
                {
                    cout<<"       ";
                }
                else{
                    cout<<" [G"<<i+1<<"] ";
                }
            }

            if(j==7)
            {
                if(i==0)
                {
                    cout<<endl;
                    cout<<"\t\tH";
                }
                if(i==5)
                {
                    cout<<"      ";
                }
                else if(i==13||i==15||i==23)
                {
                    cout<<"       ";
                }
                else{
                    cout<<" [H"<<i+1<<"] ";
                }
            }
            if(j==8)
            {
                if(i==0)
                {
                    cout<<endl;
                    cout<<"\t\tI";
                }
                if(i==5)
                {
                    cout<<"      ";
                }
                else if(i==13||i==15||i==23)
                {
                    cout<<"       ";
                }
                else{
                    cout<<" [I"<<i+1<<"] ";
                }
            }
        }
    }
    cout<<endl;
    cout<<" ____STALL_$70___";
    for(i=0;i<36;i++)
    {
        if(i>5)
        {
            cout<<"______";
        }
    }
    cout<<endl;
    for(j=0;j<12;j++)
    {
        for(i=0;i<27;i++)
        {
            if(j==9)
            {
                if(i==0)
                {
                    cout<<"\t\tJ";
                }
                if(i==8)
                {
                    cout<<"      ";
                }
                else if(i==20)
                {
                    cout<<"       ";
                }
                else{
                    cout<<" [J"<<i+1<<"] ";
                }

            }

            if(j==10)
            {
                if(i==0)
                {
                    cout<<endl;
                    cout<<"\t\tK";
                }
                if(i==8)
                {
                    cout<<"      ";
                }
                else if(i==20)
                {
                    cout<<"       ";
                }
                else{
                    cout<<" [K"<<i+1<<"] ";
                }
            }
            if(j==11)
            {
                if(i==0)
                {
                    cout<<endl;
                    cout<<"\t\tL";
                }
                if(i==8)
                {
                    cout<<"      ";
                }
                else if(i==20)
                {
                    cout<<"       ";
                }
                else{
                    cout<<" [L"<<i+1<<"] ";
                }
            }
        }
    }
    cout<<endl;
    for(i=0;i<32;i++)
    {
        if(i==0)
        {
            cout<<"     ";
        }
        else if(i==1)
        {
            cout<<"       _______";
        }
        else
        {
            cout<<"______";
        }
    }
    cout<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t    --EYES-THIS-WAY--"<<endl;
}

void DisplayTheatre :: ticket_display(int nt, int customer_choice_movie, int customer_choice_time_slot, int customer_choice_seat_type, int customer_choice_movie_theatre, char customer_choice_seat_row, int customer_choice_seat_number[], string customer_choice_language, string customer_choice_mode)
{
    int i=0, j=0;
    for(i=0;i<nt;i++)
    {
        cout<<"\t\t ";
        for(j=0;j<25;j++)
        {
            cout<<"___";
        }
        cout<<endl;
        cout<<"\t\t|";
        for(j=0;j<25;j++)
        {
            cout<<"   ";
        }
        cout<<"|"<<endl;

        cout<<"\t\t|";
        for(j=0;j<25;j++)
        {
            if(j==13)
            {
                if(customer_choice_movie_theatre==1)
                {
                    cout<<"        METRO INOX         ";
                }
                else if(customer_choice_movie_theatre==2)
                {
                    cout<<"    MUKTA A2 SUNCITY    ";
                }
                else if(customer_choice_movie_theatre==3)
                {
                    cout<<"    STERLING CINEPLEX       ";
                }
                else if(customer_choice_movie_theatre==4)
                {
                    cout<<"    LIBERTY CINEMAS    ";
                }
                else if(customer_choice_movie_theatre==5)
                {
                    cout<<"    IHRJVC CINEMAS     ";
                }

            }
            else
            {
                cout<<"  ";
            }
        }
        cout<<"|"<<endl;
        cout<<"\t\t|";
        for(j=0;j<25;j++)
        {
            if(j==13)
            {
                if(customer_choice_movie==1)
                {
                    cout<<"Doctor Strange: In The Multiverse of Madness : "<<customer_choice_time_slot;
                }
                else if(customer_choice_movie==2)
                {
                    cout<<"\t\t\tKGF : Chapter 2 : "<<customer_choice_time_slot<<"\t\t ";
                }
                else if(customer_choice_movie==3)
                {
                    cout<<"\t\t\tRunway 34 : "<<customer_choice_time_slot<<"\t\t ";
                }
                else if(customer_choice_movie==4)
                {
                    cout<<"\t\t           RRR : "<<customer_choice_time_slot<<"\t\t\t ";
                }
                else if(customer_choice_movie==5)
                {
                    cout<<"\t\t     Gangubai Kathiawadi : "<<customer_choice_time_slot<<"\t\t ";
                }

            }
            else
            {
                cout<<" ";
            }
        }
        cout<<"|"<<endl;
        cout<<"\t\t|__";
        for(j=0;j<23;j++)
        {
            cout<<"   ";
        }
        cout<<"  __|"<<endl;
        cout<<"\t\t   |";
        for(j=0;j<23;j++)
        {
            if(j==11)
                {
                    cout<<customer_choice_seat_row;
                    if(customer_choice_seat_number[i]==0 || customer_choice_seat_number[i]==1 || customer_choice_seat_number[i]==2 || customer_choice_seat_number[i]==3 || customer_choice_seat_number[i]==4 || customer_choice_seat_number[i]==5 || customer_choice_seat_number[i]==6 || customer_choice_seat_number[i]==7 || customer_choice_seat_number[i]==8 || customer_choice_seat_number[i]==9)
                    {
                        cout<<"0"<<customer_choice_seat_number[i];
                    }
                    else
                    {
                        cout<<customer_choice_seat_number[i];
                    }
                }
                else
                {
                    cout<<"   ";
                }
        }
        cout<<"|  "<<endl;

        cout<<"\t\t __|";
        for(j=0;j<22;j++)
        {
            if(j==13)
            {
                if(customer_choice_movie==1 || customer_choice_movie==3 || customer_choice_movie==4)
                {
                    cout<<" "<<customer_choice_language;
                    cout<<" | "<<customer_choice_mode;
                }
                else
                {
                    cout<<"\t\t"<<customer_choice_language;
                }
            }
            else
            {
                cout<<"  ";
            }
        }
         cout<<"\t\t |__"<<endl;

        cout<<"\t\t|";
        for(j=0;j<25;j++)
        {
            if(j==15)
            {
                if(customer_choice_seat_type==1)
                {
                    cout<<"STALL -- $70\t\t  ";
                }
                else if(customer_choice_seat_type==2)
                {
                    cout<<"BALCONY -- $120\t\t  ";
                }
                else if(customer_choice_seat_type==3)
                {
                    cout<<"RECLINER -- $220\t\t  ";
                }
            }
            else if(j==13)
            {
                if(customer_choice_seat_type==4)
                    {
                        cout<<"LUXURY DELUXE -- $500\t";
                    }
            }
            else
            {
               cout<<"  ";
            }

        }
        cout<<"|"<<endl;

        cout<<"\t\t|";
        for(j=0;j<25;j++)
        {
            if(j==20)
            {
                cout<<"\t\t     *~&@   ";// 5 spaces and 3 spaces
            }
            else
            {
                cout<<"  ";
            }
        }
        cout<<"|"<<endl;

        cout<<"\t\t|";
        for(j=0;j<25;j++)
        {
            if(j==20)
            {
                cout<<"~*%&   "; //3 spaces
            }
            else if(j==4)
            {
                cout<<"TICKET BOOKED!!!";
            }
            else if(j==18)
            {
                cout<<"QR CODE : ";
            }
            else if(j==19)
            {
                cout<<"";
            }
            else
            {
                cout<<"  ";
            }
        }
        cout<<"|"<<endl;

        cout<<"\t\t|";
        for(j=0;j<25;j++)
        {
            if(j==20)
            {
                cout<<"   #!$&   ";//3 spaces and 3spaces
            }
            else if(j==2)
            {
                cout<<"\t ~~~///(^v^)\\\~~~";
            }
            else
            {
                cout<<"  ";
            }
        }
        cout<<"|"<<endl;

        cout<<"\t\t'_";
        for(j=0;j<25;j++)
        {
            if(j==24)
            {
                cout<<"_";
            }
            else
            {
                    cout<<"___";
            }
        }
        cout<<"_'"<<endl;
    }
}

void DisplayTheatre :: theatre_info(int customer_choice_movie, int customer_choice_time_slot, int customer_choice_seat_type, int customer_choice_movie_theatre, string customer_choice_language, string customer_choice_mode)
{
    if(customer_choice_movie_theatre==1)
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t    METRO INOX"<<endl;
    }
    else if(customer_choice_movie_theatre==2)
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t MUKTA A2 SUNCITY"<<endl;
    }
    else if(customer_choice_movie_theatre==3)
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t STERLING CINEPLEX"<<endl;
    }
    else if(customer_choice_movie_theatre==4)
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t LIBERTY CINEMAS"<<endl;
    }
    else if(customer_choice_movie_theatre==5)
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t  IHRJVC CINEMAS"<<endl;
    }

    if(customer_choice_movie==1)
    {
        cout<<"\t\t\t\t\t\t\t\tDoctor Strange: In The Multiverse of Madness : "<<customer_choice_time_slot<<endl;
    }
    else if(customer_choice_movie==2)
    {
        cout<<"\t\t\t\t\t\t\t\t\t\tKGF : Chapter 2 : "<<customer_choice_time_slot<<endl;
    }
    else if(customer_choice_movie==3)
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t  Runway 34 : "<<customer_choice_time_slot<<endl;
    }
    else if(customer_choice_movie==4)
    {
        cout<<"\t\t\t\t\t\t\t\t\t\tRRR : "<<customer_choice_time_slot<<endl;
    }
    else if(customer_choice_movie==5)
    {
        cout<<"\t\t\t\t\t\t\t\t\t    Gangubai Kathiawadi : "<<customer_choice_time_slot<<endl;
    }

    if(customer_choice_seat_type==1)
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t   STALL -- $70"<<endl;
    }
    else if(customer_choice_seat_type==2)
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t  BALCONY -- $120"<<endl;
    }
    else if(customer_choice_seat_type==3)
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t  RECLINER -- $220"<<endl;
    }
    else if(customer_choice_seat_type==4)
    {
        cout<<"\t\t\t\t\t\t\t\t\t\tLUXURY DELUXE -- $500"<<endl;
    }

    cout<<"\t\t\t\t\t\t\t\t\t\t   "<<customer_choice_language;

    if(customer_choice_movie==1 || customer_choice_movie==3 || customer_choice_movie==4)
    {
        cout<<" | "<<customer_choice_mode<<endl;
    }
}

void DisplayTheatre :: display_seat_type()
{
    cout<<endl;
                                    cout<<"\t\t\t\tWe Offer the Following seats : "<<endl<<endl<<endl;
                                    cout<<"\t\t\t\t 1. Stall --- $70 --- rows J,K,L"<<endl<<endl;
                                    cout<<"\t\t\t\t 2. Balcony --- $120 --- rows F,G,H,I"<<endl<<endl;
                                    cout<<"\t\t\t\t 3. Recliner --- $220 --- rows C,D,E"<<endl<<endl;
                                    cout<<"\t\t\t\t 4. Luxury Complex --- $500 --- rows A, B"<<endl<<endl;
                                    cout<<endl;
}

main()
{
    TicketBooking TB;
    DisplayTheatre DT;
    DifferentActivity DA;
    name();
    int i=0, j=0, B, choice, customer_choice, customer_choice_movie, customer_choice_time_slot, customer_choice_seat_type, customer_choice_movie_theatre, ticket_total;
    int customer_choice_seat_number[100];
    char customer_choice_seat_row;
    string customer_choice_language, customer_choice_mode;
    float nt;

    start :
    {
        cout<<"\n\n\t\t\tWELCOME TO CODM\n"<<endl;
        cout<<"\t\t 1. Customer"<<endl;
        cout<<"\t\t 2. Manager"<<endl;
        cout<<endl;
        cout<<"\t\t Enter Your Designation : ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                {
                    user_start:
                    {
                        cout<<endl;
                        cout<<"\t\t\t 1. Login"<<endl;
                        cout<<"\t\t\t 2. Sign Up"<<endl;
                        cout<<endl;
                        cout<<"\t\t\t What Would You Like To Do? ";
                        cin>>customer_choice;

                        switch(customer_choice)
                        {

                            case 1:
                                {
                                    cout<<endl;
                                    TB.log_in_user();
                                    cout<<endl<<endl;
                                    cout<<"\t\t\tLove to See You Back"<<endl;
                                    cout<<endl<<endl;
                                    theatre:
                                        {
                                            cout<<"\t\t\t*******THEATRES*******"<<endl;
                                            cout<<"\t\t\t1. Metro Inox"<<endl;
                                            cout<<"\t\t\t2. Mukta A2 Suncity"<<endl;
                                            cout<<"\t\t\t3. Sterling Cineplex"<<endl;
                                            cout<<"\t\t\t4. Liberty Cinemas"<<endl;
                                            cout<<"\t\t\t5. IHRJVC Cinemas"<<endl;
                                            cout<<endl;
                                            cout<<"\t\t\tWhich Theatre Would You Like To Go : ";
                                            cin>>customer_choice_movie_theatre;

                                            if(customer_choice_movie_theatre>5)
                                            {
                                                cout<<endl<<endl;
                                                cout<<"Invalid Credentials"<<endl;
                                                goto theatre;
                                            }
                                        }
                                    TB.current_showtimings();
                                    cout<<endl;
                                    DA.manager_decision_show();
                                    cout<<endl<<endl;
                                    cout<<"\t\t\tWhich movie would you like to see ? ";
                                    cin>>customer_choice_movie;
                                    cout<<endl<<endl;
                                    cout<<"\t\t\t\tEnter Desired Time Slot : ";
                                    cin>>customer_choice_time_slot;
                                    cout<<endl<<endl;
                                    cout<<"\t\t\t\tEnter Preferred Language : ";
                                    cin>>customer_choice_language;
                                    cout<<endl<<endl;
                                    if(customer_choice_movie == 1 || customer_choice_movie == 3 || customer_choice_movie == 4)
                                    {
                                        cout<<"\t\t\t\tEnter Preferred Mode of Watching : ";
                                        cin>>customer_choice_mode;
                                    }
                                    cout<<endl<<endl;
                                    cout<<endl;
                                    cout<<"\t\t\t\tWe Offer the Following seats : "<<endl<<endl<<endl;
                                    cout<<"\t\t\t\t 1. Stall --- $70 --- rows J,K,L"<<endl<<endl;
                                    cout<<"\t\t\t\t 2. Balcony --- $120 --- rows F,G,H,I"<<endl<<endl;
                                    cout<<"\t\t\t\t 3. Recliner --- $220 --- rows C,D,E"<<endl<<endl;
                                    cout<<"\t\t\t\t 4. Luxury Complex --- $500 --- rows A, B"<<endl<<endl;
                                    cout<<endl;
                                    cout<<"\t\t\t\tPlease Enter your Preference : ";
                                    cin>>customer_choice_seat_type;
                                    cout<<endl;
                                    DT.seat_display();
                                    cout<<endl;
                                    DT.theatre_info(customer_choice_movie, customer_choice_time_slot, customer_choice_seat_type, customer_choice_movie_theatre, customer_choice_language, customer_choice_mode);
                                    cout<<endl<<endl;
                                    cout<<"How Many Tickets Do You Want To Book ? : ";
                                    cin>>nt;
                                    cout<<endl<<endl;

                                    switch(customer_choice_seat_type)
                                    {
                                        case 1:
                                        {
                                            int i=0;
                                            case1:
                                            {
                                                cout<<"Enter Seat Row : ";
                                                cin>>customer_choice_seat_row;
                                                while(i<3)
                                                {

                                                    if(customer_choice_seat_row=='J'||customer_choice_seat_row=='K'||customer_choice_seat_row=='L')
                                                    {
                                                        goto sen;
                                                        i=3;
                                                    }
                                                    else
                                                    {
                                                        cout<<"Invalid Row !!"<<endl;
                                                        DA.display_seat_type();
                                                        i++;
                                                        goto case1;
                                                    }
                                                }
                                            }
                                            break;
                                        }
                                        case 2:
                                        {
                                            int i=0;
                                            case2:
                                            {
                                                cout<<"Enter Seat Row : ";
                                                cin>>customer_choice_seat_row;
                                                while(i<3)
                                                {

                                                    if(customer_choice_seat_row=='F'||customer_choice_seat_row=='G'||customer_choice_seat_row=='H'||customer_choice_seat_row=='I')
                                                    {
                                                        goto sen;
                                                        i=3;
                                                    }
                                                    else
                                                    {
                                                        cout<<"Invalid Row !!"<<endl;
                                                        DA.display_seat_type();
                                                        i++;
                                                        goto case2;
                                                    }
                                                }
                                            }
                                            break;
                                        }
                                        case 3:
                                        {
                                            int i=0;
                                            case3:
                                            {
                                                cout<<"Enter Seat Row : ";
                                                cin>>customer_choice_seat_row;
                                                while(i<3)
                                                {

                                                    if(customer_choice_seat_row=='C'||customer_choice_seat_row=='D'||customer_choice_seat_row=='E')
                                                    {
                                                        goto sen;
                                                        i=3;
                                                    }
                                                    else
                                                    {
                                                        cout<<"Invalid Row !!"<<endl;
                                                        DA.display_seat_type();
                                                        i++;
                                                        goto case3;
                                                    }
                                                }
                                            }
                                            break;
                                        }
                                        case 4:
                                        {
                                            int i=0;
                                            case4:
                                            {
                                                cout<<"Enter Seat Row : ";
                                                cin>>customer_choice_seat_row;
                                                while(i<3)
                                                {

                                                    if(customer_choice_seat_row=='A'||customer_choice_seat_row=='B')
                                                    {
                                                        goto sen;
                                                        i=3;
                                                    }
                                                    else
                                                    {
                                                        cout<<"Invalid Row !!"<<endl;
                                                        DA.display_seat_type();
                                                        i++;
                                                        goto case4;
                                                    }
                                                }
                                            }
                                            break;
                                        }
                                        default:
                                        {
                                            cout<<"Invalid Choice"<<endl;
                                        }
                                    }
                                    sen:
                                    {
                                        cout<<"Enter Seat No. : "<<endl;

                                        for(j=0;j<nt;j++)
                                        {
                                            cout<<"\t Data "<<j+1<<" : ";
                                            cin>>customer_choice_seat_number[j];
                                        }
                                    }
                                    cout<<endl<<endl;

                                    ticket_total = TB.calculate_total(customer_choice_seat_type, nt);
                                    DA.food_beverage();
                                    DA.bill_display(nt, customer_choice_movie, customer_choice_time_slot, customer_choice_seat_type, customer_choice_movie_theatre, customer_choice_seat_row, customer_choice_seat_number, customer_choice_language, customer_choice_mode, DA.f, DA.b, DA.bp, DA.food_items_number, DA.np, DA.npa, DA.ngb, DA.ns, DA.nf, DA.nn, DA.num_beverages, DA.num_soft_drink, DA.num_milk_drink, DA.choice_bucket_popcorn, DA.choice_bucket_size, DA.choice_pizza, DA.choice_pizza_size, DA.choice_fries, DA.choice_fries_size, DA.choice_soft_drink, DA.choice_milk_drink);
                                    Sleep(5000);
                                    DT.ticket_display(nt, customer_choice_movie, customer_choice_time_slot, customer_choice_seat_type, customer_choice_movie_theatre, customer_choice_seat_row, customer_choice_seat_number, customer_choice_language, customer_choice_mode);
                                    break;
                                }
                            case 2:
                                {
                                    cout<<endl<<endl;
                                    TB.sign_up_user();
                                    cout<<endl<<endl;
                                    cout<<"Thank you for signing up with us"<<endl;
                                    cout<<endl<<endl;
                                    theatre1:
                                        {
                                            cout<<"\t\t\t*******THEATRES*******"<<endl;
                                            cout<<"\t\t\t1. Metro Inox"<<endl;
                                            cout<<"\t\t\t2. Mukta A2 Suncity"<<endl;
                                            cout<<"\t\t\t3. Sterling Cineplex"<<endl;
                                            cout<<"\t\t\t4. Liberty Cinemas"<<endl;
                                            cout<<"\t\t\t5. IHRJVC Cinemas"<<endl;
                                            cout<<endl;
                                            cout<<"\t\t\tWhich Theatre Would You Like To Go : ";
                                            cin>>customer_choice_movie_theatre;

                                            if(customer_choice_movie_theatre>5)
                                            {
                                                cout<<endl<<endl;
                                                cout<<"Invalid Credentials"<<endl;
                                                goto theatre1;
                                            }
                                        }
                                    TB.current_showtimings();
                                    cout<<endl;
                                    DA.manager_decision_show();
                                    cout<<endl<<endl;
                                    cout<<"\t\t\tWhich movie would you like to see ? ";
                                    cin>>customer_choice_movie;
                                    cout<<endl<<endl;
                                    cout<<"\t\t\t\tEnter Desired Time Slot : ";
                                    cin>>customer_choice_time_slot;
                                    cout<<endl<<endl;
                                    cout<<"\t\t\t\tEnter Preferred Language : ";
                                    cin>>customer_choice_language;
                                    cout<<endl<<endl;
                                    if(customer_choice_movie == 1 || customer_choice_movie == 3 || customer_choice_movie == 4)
                                    {
                                        cout<<"\t\t\t\tEnter Preferred Mode of Watching : ";
                                        cin>>customer_choice_mode;
                                    }
                                    cout<<endl<<endl;
                                    cout<<endl;
                                    cout<<"\t\t\t\tWe Offer the Following seats : "<<endl<<endl<<endl;
                                    cout<<"\t\t\t\t 1. Stall --- $70 --- rows J,K,L"<<endl<<endl;
                                    cout<<"\t\t\t\t 2. Balcony --- $120 --- rows F,G,H,I"<<endl<<endl;
                                    cout<<"\t\t\t\t 3. Recliner --- $220 --- rows C,D,E"<<endl<<endl;
                                    cout<<"\t\t\t\t 4. Luxury Complex --- $500 --- rows A, B"<<endl<<endl;
                                    cout<<endl;
                                    cout<<"\t\t\t\tPlease Enter your Preference : ";
                                    cin>>customer_choice_seat_type;
                                    cout<<endl;
                                    DT.seat_display();
                                    cout<<endl;
                                    DT.theatre_info(customer_choice_movie, customer_choice_time_slot, customer_choice_seat_type, customer_choice_movie_theatre, customer_choice_language, customer_choice_mode);
                                    cout<<endl<<endl;
                                    cout<<"How Many Tickets Do You Want To Book ? : ";
                                    cin>>nt;
                                    cout<<endl<<endl;

                                    switch(customer_choice_seat_type)
                                    {
                                        case 1:
                                        {
                                            int i=0;
                                            case2_1:
                                            {
                                                cout<<"Enter Seat Row : ";
                                                cin>>customer_choice_seat_row;
                                                while(i<3)
                                                {

                                                    if(customer_choice_seat_row=='J'||customer_choice_seat_row=='K'||customer_choice_seat_row=='L')
                                                    {
                                                        goto sen2;
                                                        i=3;
                                                    }
                                                    else
                                                    {
                                                        cout<<"Invalid Row !!"<<endl;
                                                        DA.display_seat_type();
                                                        i++;
                                                        goto case2_1;
                                                    }
                                                }
                                            }
                                            break;
                                        }
                                        case 2:
                                        {
                                            int i=0;
                                            case2_2:
                                            {
                                                cout<<"Enter Seat Row : ";
                                                cin>>customer_choice_seat_row;
                                                while(i<3)
                                                {

                                                    if(customer_choice_seat_row=='F'||customer_choice_seat_row=='G'||customer_choice_seat_row=='H'||customer_choice_seat_row=='I')
                                                    {
                                                        goto sen2;
                                                        i=3;
                                                    }
                                                    else
                                                    {
                                                        cout<<"Invalid Row !!"<<endl;
                                                        DA.display_seat_type();
                                                        i++;
                                                        goto case2_2;
                                                    }
                                                }
                                            }
                                            break;
                                        }
                                        case 3:
                                        {
                                            int i=0;
                                            case2_3:
                                            {
                                                cout<<"Enter Seat Row : ";
                                                cin>>customer_choice_seat_row;
                                                while(i<3)
                                                {

                                                    if(customer_choice_seat_row=='C'||customer_choice_seat_row=='D'||customer_choice_seat_row=='E')
                                                    {
                                                        goto sen2;
                                                        i=3;
                                                    }
                                                    else
                                                    {
                                                        cout<<"Invalid Row !!"<<endl;
                                                        DA.display_seat_type();
                                                        i++;
                                                        goto case2_3;
                                                    }
                                                }
                                            }
                                            break;
                                        }
                                        case 4:
                                        {
                                            int i=0;
                                            case2_4:
                                            {
                                                cout<<"Enter Seat Row : ";
                                                cin>>customer_choice_seat_row;
                                                while(i<3)
                                                {

                                                    if(customer_choice_seat_row=='A'||customer_choice_seat_row=='B')
                                                    {
                                                        goto sen2;
                                                        i=3;
                                                    }
                                                    else
                                                    {
                                                        cout<<"Invalid Row !!"<<endl;
                                                        DA.display_seat_type();
                                                        i++;
                                                        goto case2_4;
                                                    }
                                                }
                                            }
                                            break;
                                        }
                                        default:
                                        {
                                            cout<<"Invalid Choice"<<endl;
                                        }
                                    }
                                    sen2:
                                    {
                                        cout<<"Enter Seat No. : "<<endl;

                                        for(j=0;j<nt;j++)
                                        {
                                            cout<<"\t Data "<<j+1<<" : ";
                                            cin>>customer_choice_seat_number[j];
                                        }
                                    }
                                    cout<<endl<<endl;

                                    ticket_total = TB.calculate_total(customer_choice_seat_type, nt);
                                    DA.food_beverage();
                                    DA.bill_display(nt, customer_choice_movie, customer_choice_time_slot, customer_choice_seat_type, customer_choice_movie_theatre, customer_choice_seat_row, customer_choice_seat_number, customer_choice_language, customer_choice_mode, DA.f, DA.b, DA.bp, DA.food_items_number, DA.np, DA.npa, DA.ngb, DA.ns, DA.nf, DA.nn, DA.num_beverages, DA.num_soft_drink, DA.num_milk_drink, DA.choice_bucket_popcorn, DA.choice_bucket_size, DA.choice_pizza, DA.choice_pizza_size, DA.choice_fries, DA.choice_fries_size, DA.choice_soft_drink, DA.choice_milk_drink);
                                    Sleep(5000);
                                    DT.ticket_display(nt, customer_choice_movie, customer_choice_time_slot, customer_choice_seat_type, customer_choice_movie_theatre, customer_choice_seat_row, customer_choice_seat_number, customer_choice_language, customer_choice_mode);
                                    break;
                                }
                            default :
                                {
                                    cout<<endl<<endl;
                                    do
                                    {
                                        cout<<"Please Enter Valid Choice : "<<endl;
                                        cout<<endl<<endl;
                                        cout<<endl<<endl;
                                        goto user_start;
                                        i += 1;
                                    }while(i<3);
                                    break;
                                }
                            }
                    }
                break;
                }
            case 2:
                {
                    cout<<endl<<endl;
                    TB.if_manager();
                    cout<<endl<<endl;
                    TB.current_showtimings();
                    DA.manager_decision1();
                    goto start;
                    cout<<endl<<endl;
                    break;
                }
            default :
                {
                    cout<<endl<<endl;
                    do
                        {
                            cout<<"Invalid Credentials"<<endl;
                            cout<<endl<<endl;
                            cout<<endl<<endl;
                            i += 1;
                            goto start;
                        }while(i<3);
                    break;
                }
            }
    }
}
