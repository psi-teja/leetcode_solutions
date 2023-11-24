#include <iostream>
#include <set>


class ExamRoom {
private:
    int roomSize;
    std::set<int> occupiedSeats;

public:

    ExamRoom(int n) {
        roomSize = n;
    }
    
    int seat() {

        if (occupiedSeats.empty()){
            occupiedSeats.insert(0);
        }

        int  bestSeat = 0;

        

        return bestSeat;   
    }
    
    void leave(int p) {
       occupiedSeats.erase(p); 
    }
};


int main() {
    ExamRoom examRoom(10);

    // First student enters
    std::cout << "Seat: " << examRoom.seat() << std::endl;

    // Another student enters
    std::cout << "Seat: " << examRoom.seat() << std::endl;

    // Student at seat 0 leaves
    examRoom.leave(0);

    // Another student enters
    std::cout << "Seat: " << examRoom.seat() << std::endl;

    // Another student enters
    std::cout << "Seat: " << examRoom.seat() << std::endl;

    return 0;
}
