#include <iostream>
#include <bits/stdc++.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

// Constants
#define FINISH_DISTANCE (ll)10000000
#define HARE_STEPS_AT_ONCE 5
#define MIN_DIST_TO_SLEEP 1e8

using namespace std;
using ll = long long int;

ll hare_dist = 0;
ll turtle_dist = 0;

ll hare_time = 0;
ll turtle_time = 0;


// 0 == God chooses random positions
// 1 == God asks user for new positions
int interface_type=0; 

pthread_t reporter_thread_id, god_thread_id, turtle_thread_id, hare_thread_id;

pthread_mutex_t turtle_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t hare_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t terminal_mutex = PTHREAD_MUTEX_INITIALIZER;

ll getRandomDistance() {
    return rand()%(FINISH_DISTANCE+1);
}
bool getRandomCondition(){
    return ( (double) rand() / (RAND_MAX) ) >= 0.8;
}
void *turtle_run(void *args) {
    while(turtle_dist < FINISH_DISTANCE) {
        pthread_mutex_lock (&turtle_mutex);
        turtle_dist++;
        turtle_time++;
        pthread_mutex_unlock (&turtle_mutex);
    }
    return (void *) 0;
}
void *hare_run(void *args) {
    while(hare_dist < FINISH_DISTANCE) {
        if(hare_dist-turtle_dist >= MIN_DIST_TO_SLEEP) {
            ll sleep_time = rand()%(10000000);
            hare_time += sleep_time;

            ll random_sleep = rand()%1000; // 0 - 999
            usleep(random_sleep);
        }
        pthread_mutex_lock (&hare_mutex);
        hare_dist += HARE_STEPS_AT_ONCE;
        hare_time++;
        pthread_mutex_unlock (&hare_mutex);
    }
    return (void *) 0;
}
void *reporter_run(void *args) {
    while(turtle_dist < FINISH_DISTANCE || hare_dist < FINISH_DISTANCE) {
        pthread_mutex_lock (&terminal_mutex);
        cout << "\n<><><><><><><><><> RACE DETAILS <><><><><><><><><>\n";
        cout << "\n turtle is at a distance of : " << turtle_dist << "\t, at time : " << turtle_time << " iterations";
        cout << "\n   Hare   is at a distance of : " << hare_dist << "\t, at time : " << hare_time << " iterations\n";

        pthread_mutex_unlock (&terminal_mutex);
        usleep(500);
    }
    if(turtle_dist >= FINISH_DISTANCE || hare_dist >= FINISH_DISTANCE){
        cout<< "\n<><><><><><><><><> RACE IS OVER <><><><><><><><><>\n";
        cout<< "\n Race is Completed \n\n";
        cout<< "\tturtle's Time   : " << turtle_time << " iterations\n";
        cout<< "\tHare's Time     : "<< hare_time << " iterations\n";

        if (turtle_time < hare_time) {
            cout << "\n\tRace's Winner is 'turtle'\n";
        } else if (turtle_time > hare_time) {
            cout << "\n\tRace's Winner is 'hare'.\n";
        } else {
            cout << "\n\tThe race is drawn\n";
        }
        cout<< "\n<><><><><><><><><><><><><><><><><><><><><><><><><><>\n";
        exit(3);
    }

    return (void *) 0;
}
void *god_run(void *args) {

//    pthread_create (&reporter_thread_id, NULL, reporter_run, NULL);
//    pthread_create (&turtle_thread_id, NULL, turtle_run, NULL);
//    pthread_create (&hare_thread_id, NULL, hare_run, NULL);
//
//
//    pthread_join (turtle_thread_id, NULL);
//    pthread_join (hare_thread_id, NULL);
//    pthread_join (reporter_thread_id, NULL);

    while(turtle_dist < FINISH_DISTANCE || hare_dist < FINISH_DISTANCE) {
        // halt reporter, turtle and hare using mutex
        pthread_mutex_lock (&terminal_mutex);
        pthread_mutex_lock (&turtle_mutex);
        pthread_mutex_lock (&hare_mutex);

        if(getRandomCondition()){
            cout<<"\n God has changed positions...\n";
            cout<<"\n<><><><><><><> NEW POSITIONS <><><><><><><><><>\n\n";
            if(!interface_type){
                if(turtle_dist < FINISH_DISTANCE) {
                    turtle_dist = getRandomDistance();
                    cout<<" turtle = "<< turtle_dist << "\n";
                }
                if(hare_dist < FINISH_DISTANCE) {
                    hare_dist = getRandomDistance();
                    cout<<" Hare     = "<< hare_dist << "\n";
                }
            }else{
                if(turtle_dist < FINISH_DISTANCE) {
                    cout<<"Enter turtle Distance : ";
                    cin>> turtle_dist;
                    cout<<" turtle = "<< turtle_dist << "\n";
                }
                if(hare_dist < FINISH_DISTANCE) {
                    cout<<"Enter Hare Distance : ";
                    cin>>hare_dist;
                    cout<<" Hare     = "<< hare_dist << "\n";
                }
            }
            

        } else {

            pthread_mutex_unlock(&terminal_mutex);
            pthread_mutex_unlock(&turtle_mutex);
            pthread_mutex_unlock(&hare_mutex);

            usleep(500);
            continue;

        }

        pthread_mutex_unlock(&terminal_mutex);
        pthread_mutex_unlock(&turtle_mutex);
        pthread_mutex_unlock(&hare_mutex);
    
    }

    return (void *) 0;
}

int main() {

    srand(time(NULL));

    cout<<"Choose the Interface Type \n";
    cout<<"Type 0 for God to choose random values for new positions on interferance \n";
    cout<<"Type 1 for God to ask user for new positions \n";
    //cin>>interface_type;
    if(interface_type!=0 && interface_type!=1){
        cout<<"\nExiting Problem for invalid values";
        return 1;
    }
    cout<<"\nThe Race Target Distance is :"<<FINISH_DISTANCE;


    pthread_create (&god_thread_id, NULL, god_run, NULL);
    pthread_create (&turtle_thread_id, NULL, turtle_run, NULL);
    pthread_create (&hare_thread_id, NULL, hare_run, NULL);
    pthread_create (&reporter_thread_id, NULL, reporter_run, NULL);

    pthread_join (god_thread_id, NULL);
    pthread_join (turtle_thread_id, NULL);
    pthread_join (hare_thread_id, NULL);
    pthread_join (reporter_thread_id, NULL);

    return 0;
}