#include<iostream>
#include<vector>

using namespace std;

class MyCalendar {
private:
    vector<pair<int,int>> booked;

public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {

        for (const auto& meeting: booked){
            if  ((meeting.first <= start && start < meeting.second) || (meeting.first < end && end <= meeting.second))
{
                return false;
            }
        }
        booked.push_back({start,end});
        return true;
    }
};

int main() {
    std::vector<std::pair<std::string, std::pair<int, int>>> input = {
{"MyCalendar", {0, 0}},
        {"book", {97, 100}},
        {"book", {33, 51}},
        {"book", {89, 100}},
        {"book", {83, 100}},
        {"book", {75, 92}},
        {"book", {76, 95}},
        {"book", {19, 30}},
        {"book", {53, 63}},
        {"book", {8, 23}},
        {"book", {18, 37}},
        {"book", {87, 100}},
        {"book", {83, 100}},
        {"book", {54, 67}},
        {"book", {35, 48}},
        {"book", {58, 75}},
        {"book", {70, 89}},
        {"book", {13, 32}},
        {"book", {44, 63}},
        {"book", {51, 62}},
        {"book", {2, 15}}
    };

    MyCalendar* obj = nullptr;

    for (const auto& command : input) {
        const std::string& cmd = command.first;
        const std::pair<int, int>& args = command.second;

        if (cmd == "MyCalendar") {
            delete obj;
            obj = new MyCalendar();
        } else if (cmd == "book") {
            bool result = obj->book(args.first, args.second);
            std::cout << "Booking from " << args.first << " to " << args.second << ": " << result << std::endl;
        }
    }

    delete obj;  // Don't forget to free the allocated memory

    return 0;
}


// [null,true,true,false,false,true,false,true,true,false,false,false,false,false,false,false,false,false,false,false,true]