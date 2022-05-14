#include<iostream>
#include<string>
#include<bits/stdc++.h>
#include<queue>
#include<vector>


using namespace std;

double T;
int N;
bool simulation_end=false;

class Packets{
    private: 
        double packet_size;
    public:
        double trigger_time; // stores the trigger time of the packet
        double receive_time; // calculates and stores the receiving time
        bool received_with_error=false; // shows the message that the packet was received with error
        double transmission_delay; // transmission delay quantity of the package

        Packets(){ // constructor
            packet_size=0;
            trigger_time=0;
            transmission_delay=0;
            receive_time=0;
        }

        Packets(double t){
            packet_size=rand()%950+50;
            trigger_time=((double)rand()/RAND_MAX)*T/100+t;
            transmission_delay=packet_size/1000;
            receive_time=transmission_delay+trigger_time;
        }

        double getTriggerTime(){
            return trigger_time;
        }

        double getReceiveTime(){
            return receive_time;
        }

};

struct comp_trigger{

    // used it to define the comparison rule for stl priority queue
    bool operator()(Packets const &a, Packets const &b){

        return a.trigger_time > b.trigger_time;
    }     
};

struct comp_receive{
    // used it to define the comparison rule for stl priority queue
    bool operator()(Packets const &a, Packets const &b){
        return a.receive_time > b.receive_time;
    }

};

int main(){
    srand(time(0));
    cin>>T;
    cin>>N;
    double t=0;

    // queue to store the packets according to the priority of the least trigger time
    priority_queue<Packets,vector<Packets>,comp_trigger> trigger;

    for(int i=0;i<N;++i){

        trigger.push(Packets(t));
    }

    priority_queue<Packets,vector<Packets>,comp_receive> currently_in_air;

    while((!trigger.empty()||!currently_in_air.empty())){
        // if the event is triggered
        // if receive event is triggered then check the size of the stack

        Packets spare=trigger.top();
        trigger.pop();

        t=spare.trigger_time;

        while(!currently_in_air.empty()){
            Packets s=currently_in_air.top();

            if (t>s.receive_time){
                if (s.received_with_error){
                    cout<<"Time: "<<s.receive_time<<" -> Packet received with error"<<endl;
                }
                else{
                    cout<<"Time: "<<s.receive_time<<" -> Packet received was fine"<<endl;
                }
                currently_in_air.pop();
            }
            else{
                break;
            }
        }

        // checking if the queue is empty
        if (!currently_in_air.empty()){
            // if the packets are still in air then mark the packet with error
            if (currently_in_air.size()==1){
                Packets y=currently_in_air.top();
                currently_in_air.pop();
                y.received_with_error=true;
                currently_in_air.push(y);
            }
            spare.received_with_error=true;
        }

        if (t>T){
            // TIME IS UP!! break out of loop
            cout<<"Times Up!!"<<endl;
            break;
        }
        
        cout<<"Time: "<<t<<" -> Packet is triggered"<<endl;

        // pushing it to the queue according to the receive time
        currently_in_air.push(spare);

        // pushing the new generated packet to the priority queues
        Packets newPacket=Packets(t);
        trigger.push(newPacket);

        // checking if other Packets have same trigger time or not
        while(!trigger.empty()){
            // if the packets after spare have same trigger time then 
            Packets s=trigger.top();
            if (s.trigger_time==t){
                s.received_with_error=true;
                currently_in_air.push(s);
                trigger.pop();
                cout<<"Time: "<<t<<" -> Packet is triggered"<<endl;
            }
            else{
                break;
            }
        }

    }

}