


#include <cstddef>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <string>
using namespace std;
// do not start a variable name has to be a lettter not a number
// C++ program to demonstrate isdigit()
#include <ctype.h>
#include <iostream>
using namespace std;

bool isValidElevatorString( string elevatorString )
{
    // first function
    int moving =1;
    char last_value;
    if (elevatorString[0] != 'M') {
        return false;
    }
    // if m is not the fist letter than it is false
    int current_passengers = 0;
    for(int i = 0; i < elevatorString.size(); i++){
                // if current passengers = 0, and it is being substracted
        if (current_passengers < 0) {
            return false;
            break;
        }
        // if passengers is less than 0 then false
        if(elevatorString.size() <2){
            return false;
            break;
        }
        // if the size is less than 2 in lenght then return false
        if(i == 0){
            last_value = elevatorString[i];
            continue;
        }
        // if i == 0 then set last value to that
        if(last_value == 'M'){
            if(isdigit(elevatorString[i])){
                last_value = elevatorString[i];
                continue;
            }
            else if(elevatorString[i] != isdigit(elevatorString[i])){
                return false;
                break;
            }
        }
        // if last value = m and the next value is = a digit then cintinue
        // if not then false
        else if (isdigit(elevatorString[i])){
            if (last_value == '+') {
                if(isdigit(elevatorString[i+2])&&isdigit(elevatorString[i+1])){
                    int digit = int(elevatorString[i+2] -48);
                    int total = 10*((int)elevatorString[i+1]-48);
                    int total2 = 100*((int)elevatorString[i]-48);
                    int sum = total2+total + digit;
                    
                    current_passengers += sum;
                    last_value = elevatorString[i];
                    continue;
                }
                if(isdigit(elevatorString[i+1])){
                    int digit = int(elevatorString[i+1] -48);
                    int total = 10*((int)elevatorString[i]-48);
                    int sum = total + digit;
                    current_passengers += sum;
                    last_value = elevatorString[i];
                    continue;
                }
                else{
                    current_passengers = current_passengers + ((int)elevatorString[i] - 48);
                    last_value = elevatorString[i];
                    continue;
                }
                
            }
            if (last_value == '-') {
                if (current_passengers < 0) {
                    return false;
                    break;
                }
                if(isdigit(elevatorString[i+2])&&isdigit(elevatorString[i+1])){
                    int digit = int(elevatorString[i+2] -48);
                    int total = 10*((int)elevatorString[i+1]-48);
                    int total2 = 100*((int)elevatorString[i]-48);
                    int sum = total2+total + digit;
                    
                    current_passengers -= sum;
                    last_value = elevatorString[i];
                    if (current_passengers < 0) {
                        return false;
                        break;
                    }
                    continue;
                }
                if(isdigit(elevatorString[i+1])){
                    int digit = int(elevatorString[i+1] -48);
                    int total = 10*((int)elevatorString[i]-48);
                    int sum = total + digit;
                    
                    current_passengers -= sum;
                    last_value = elevatorString[i];
                    if (current_passengers < 0) {
                        return false;
                        break;
                    }
                    continue;
                    
                }
                
                else{
                    current_passengers = current_passengers - ((int)elevatorString[i] - 48);
                    last_value = elevatorString[i];
                    if (current_passengers < 0) {
                        return false;
                        break;
                    }
                    continue;
                }

            }

            last_value = elevatorString[i];
            continue;
        }
        // this adds or substracts the total passengers so that you have a current passenger at any given time.
        if(last_value == 'C'){
            if(elevatorString[i] == 'M'){
                last_value == 'M';
                continue;
                
            }
        }
        // if the last value was C, and the current is M then update it
        if (elevatorString[i] == 'O'){
            if(isdigit(elevatorString[i+1])){
                return false;
                break;
            }
               if(elevatorString[i+1] == 'O'){
                   return false;
            }
            moving = 0;
            last_value = elevatorString[i];
            continue;
        }
        // if elevator string is O, then allow posibility to use charecters like +, -, or even C
        if (moving == 0){
            if(last_value == 'O'){
                if (elevatorString[i] == 'M'|| elevatorString[i] == 'O') {
                    return false;
                    break;
                }
                else if (elevatorString[i] == '+'|| elevatorString[i] == '-'){
                    last_value = elevatorString[i];
                    continue;
                }
                else if (elevatorString[i] == 'C'){
                    last_value = elevatorString[i];
                    moving =1;
                    continue;
                }
            }
            // certain things that you can do when moving = 0 and last value is O
            if(last_value == '+'){
                if(elevatorString[i] == 'M'){
                    return false;
                    break;
                }
                else if(elevatorString[i] == '+' || elevatorString[i] == '-' || elevatorString[i] == 'C' ||elevatorString[i] == 'O'){
                    return false;
                    break;
                }
                else if (isdigit(elevatorString[i])){
                    
                        char c = elevatorString[i];
                        int n = c;
                        current_passengers += n;
            
                    last_value = elevatorString[i];
                    continue;
                }
            }
            // if last value = 0, then these are teh certain amount of char that you can use that are stated to this
            if(last_value == '-'){
                if(elevatorString[i] == 'M'){
                    return false;
                    break;
                }
                else if(elevatorString[i] == '+' || elevatorString[i] == '-' || elevatorString[i] == 'C' ||elevatorString[i] == 'O'){
                    return false;
                    break;
                }
                else if (isdigit(elevatorString[i])){
                    last_value = elevatorString[i];
                    char c = elevatorString[i];
                    int n = c;
                    current_passengers -= n;
                    if (current_passengers < 0) {
                        return false;
                        break;
                    }
                    continue;
                }
            }
            // if last value = 0, then these are teh certain amount of char that you can use that are stated to this

            if(isdigit(last_value)){
                if(elevatorString[i] == 'M'){
                    return false;
                    break;
                }
                else if(elevatorString[i] == 'O'){
                    return false;
                    break;
                }
                if(elevatorString[i] == '+' || elevatorString[i] == '-' ){
                    last_value = elevatorString[i];
                    continue;
                }
                else if (isdigit(elevatorString[i])){
                    last_value = elevatorString[i];
                    continue;
                }
                if(elevatorString[i] == 'C' ){
                    moving = 1;
                    last_value = elevatorString[i];
                    continue;
                }
            }
            
        }
        // if the digit was the last value then you cannot use M, but for other things that they could have used such as C
        if (moving == 1){
            if (elevatorString[i] == '+'||elevatorString[i] == '-'||elevatorString[i] == 'C'){
                return false;
            break;
            }
        }
        
    }
    return true;
    
}
bool doorsOpen(string elevatorString){
    // to summarize what is happeing O and C are assgined to varaibles and what is happnein gis that we are using found as a varuabe that will look at the last value then give the index int value to that found varaible
    // next it will determine which value is greatest and based on that it will declare true / false
    if(isValidElevatorString(elevatorString) == false){
        return false;
    }
    char ch = 'O';
    char hc = 'C';
    size_t found;
    size_t found2;
    found = elevatorString.find_last_of(ch);
    found2 = elevatorString.find_last_of(hc);
    found = int(found);
    found2 = int(found2);
    string s = elevatorString;
    if (s.find('C') != string::npos){
        if (found > found2){
           
            return true;
            
        }
        if (found < found2){
            
            return false;
            
        }
    }
        else{
        return false;
    
         }
    return false;
}

int endingPassengers(string elevatorString){
    // takes the current passegners that was defined in the other function as a variable on its own, it will then reitereate the cutrrent passegners until the end and then give you the remaing number
    if(isValidElevatorString(elevatorString) == false){
        return -1;
    }
    int moving =1;
    char last_value;
    if (elevatorString[0] != 'M') {
        return false;
    }
    int current_passengers = 0;
    for(int i = 0; i < elevatorString.size(); i++){
        
        
        if (current_passengers < 0) {
            return false;
            break;
        }
        if(elevatorString.size() <2){
            return false;
            break;
        }
        if(i == 0){
            last_value = elevatorString[i];
            continue;
        }
        if(last_value == 'M'){
            if(isdigit(elevatorString[i])){
                last_value = elevatorString[i];
                continue;
            }
            else if(elevatorString[i] != isdigit(elevatorString[i])){
                return false;
                break;
            }
        }
        else if (isdigit(elevatorString[i])){
            if (last_value == '+') {
                if(isdigit(elevatorString[i+2])&&isdigit(elevatorString[i+1])){
                    int digit = int(elevatorString[i+2] -48);
                    int total = 10*((int)elevatorString[i+1]-48);
                    int total2 = 100*((int)elevatorString[i]-48);
                    int sum = total2+total + digit;
                    
                    current_passengers += sum;
                    last_value = elevatorString[i];
                    continue;
                }
                if(isdigit(elevatorString[i+1])){
                    int digit = int(elevatorString[i+1] -48);
                    int total = 10*((int)elevatorString[i]-48);
                    int sum = total + digit;
                    current_passengers += sum;
                    last_value = elevatorString[i];
                    continue;
                }
                else{
                    current_passengers = current_passengers + ((int)elevatorString[i] - 48);
                    last_value = elevatorString[i];
                    continue;
                }
                
            }
            if (last_value == '-') {
                if (current_passengers < 0) {
                    return false;
                    break;
                }
                if(isdigit(elevatorString[i+2])&&isdigit(elevatorString[i+1])){
                    int digit = int(elevatorString[i+2] -48);
                    int total = 10*((int)elevatorString[i+1]-48);
                    int total2 = 100*((int)elevatorString[i]-48);
                    int sum = total2+total + digit;
                    
                    current_passengers -= sum;
                    last_value = elevatorString[i];
                    if (current_passengers < 0) {
                        return false;
                        break;
                    }
                    continue;
                }
                if(isdigit(elevatorString[i+1])){
                    int digit = int(elevatorString[i+1] -48);
                    int total = 10*((int)elevatorString[i]-48);
                    int sum = total + digit;
                    
                    current_passengers -= sum;
                    last_value = elevatorString[i];
                    if (current_passengers < 0) {
                        return false;
                        break;
                    }
                    continue;
                    
                }
                
                else{
                    current_passengers = current_passengers - ((int)elevatorString[i] - 48);
                    last_value = elevatorString[i];
                    if (current_passengers < 0) {
                        return false;
                        break;
                    }
                    continue;
                }

            }

            last_value = elevatorString[i];
            continue;
        }
        
        if(last_value == 'C'){
            if(elevatorString[i] == 'M'){
                last_value == 'M';
                continue;
                
            }
        }
        if (elevatorString[i] == 'O'){
            if(isdigit(elevatorString[i+1])){
                return false;
                break;
            }
               if(elevatorString[i+1] == 'O'){
                   return false;
            }
            moving = 0;
            last_value = elevatorString[i];
            continue;
        }
        
        if (moving == 0){
            if(last_value == 'O'){
                if (elevatorString[i] == 'M'|| elevatorString[i] == 'O') {
                    return false;
                    break;
                }
                else if (elevatorString[i] == '+'|| elevatorString[i] == '-'){
                    last_value = elevatorString[i];
                    continue;
                }
                else if (elevatorString[i] == 'C'){
                    last_value = elevatorString[i];
                    moving =1;
                    continue;
                }
            }
            if(last_value == '+'){
                if(elevatorString[i] == 'M'){
                    return false;
                    break;
                }
                else if(elevatorString[i] == '+' || elevatorString[i] == '-' || elevatorString[i] == 'C' ||elevatorString[i] == 'O'){
                    return false;
                    break;
                }
                else if (isdigit(elevatorString[i])){
                    
                        char c = elevatorString[i];
                        int n = c;
                        current_passengers += n;
            
                    last_value = elevatorString[i];
                    continue;
                }
            }
            if(last_value == '-'){
                if(elevatorString[i] == 'M'){
                    return false;
                    break;
                }
                else if(elevatorString[i] == '+' || elevatorString[i] == '-' || elevatorString[i] == 'C' ||elevatorString[i] == 'O'){
                    return false;
                    break;
                }
                else if (isdigit(elevatorString[i])){
                    last_value = elevatorString[i];
                    char c = elevatorString[i];
                    int n = c;
                    current_passengers -= n;
                    if (current_passengers < 0) {
                        return false;
                        break;
                    }
                    continue;
                }
            }
            if(isdigit(last_value)){
                if(elevatorString[i] == 'M'){
                    return false;
                    break;
                }
                else if(elevatorString[i] == 'O'){
                    return false;
                    break;
                }
                if(elevatorString[i] == '+' || elevatorString[i] == '-' ){
                    last_value = elevatorString[i];
                    continue;
                }
                else if (isdigit(elevatorString[i])){
                    last_value = elevatorString[i];
                    continue;
                }
                if(elevatorString[i] == 'C' ){
                    moving = 1;
                    last_value = elevatorString[i];
                    continue;
                }
            }
            
        }
        if (moving == 1){
            if (elevatorString[i] == '+'||elevatorString[i] == '-'||elevatorString[i] == 'C'){
                return false;
            break;
            }
        }
        
    }
return current_passengers;
}

int mostPassengers(string elevatorString){
    // this string incorporates most if not all of the code that is on the isvalidelevatorstring so the code that is here is quite self explanitory when you reread the commens on  the previous one, the only differentce is that this is an int function and the next thing is that it will incorporate another variabe called most passengers that willonly change when the current passengers is proven to be greater than
    if(isValidElevatorString(elevatorString) == false){
        return -1;
    }
    int most_passengers = 0;
    int moving =1;
    char last_value;
    if (elevatorString[0] != 'M') {
        return false;
    }
    int current_passengers = 0;
    for(int i = 0; i < elevatorString.size(); i++){
        
        if (most_passengers < current_passengers){
            most_passengers = current_passengers;
        }
        if (current_passengers < 0) {
            return false;
            break;
        }
        if(elevatorString.size() <2){
            return false;
            break;
        }
        if(i == 0){
            last_value = elevatorString[i];
            continue;
        }
        if(last_value == 'M'){
            if(isdigit(elevatorString[i])){
                last_value = elevatorString[i];
                continue;
            }
            else if(elevatorString[i] != isdigit(elevatorString[i])){
                return false;
                break;
            }
        }
        else if (isdigit(elevatorString[i])){
            if (last_value == '+') {
                if(isdigit(elevatorString[i+2])&&isdigit(elevatorString[i+1])){
                    int digit = int(elevatorString[i+2] -48);
                    int total = 10*((int)elevatorString[i+1]-48);
                    int total2 = 100*((int)elevatorString[i]-48);
                    int sum = total2+total + digit;
                    
                    current_passengers += sum;
                    last_value = elevatorString[i];
                    if(most_passengers < current_passengers){
                        most_passengers = current_passengers;
                    }
                    continue;
                }
                if(isdigit(elevatorString[i+1])){
                    int digit = int(elevatorString[i+1] -48);
                    int total = 10*((int)elevatorString[i]-48);
                    int sum = total + digit;
                    current_passengers += sum;
                    last_value = elevatorString[i];
                    if(most_passengers < current_passengers){
                        most_passengers = current_passengers;
                    }
                    continue;
                }
                else{
                    current_passengers = current_passengers + ((int)elevatorString[i] - 48);
                    last_value = elevatorString[i];
                    if(most_passengers < current_passengers){
                        most_passengers = current_passengers;
                    }
                    continue;
                }
                
            }
            if (last_value == '-') {
                if (current_passengers < 0) {
                    return false;
                    break;
                }
                if(isdigit(elevatorString[i+2])&&isdigit(elevatorString[i+1])){
                    int digit = int(elevatorString[i+2] -48);
                    int total = 10*((int)elevatorString[i+1]-48);
                    int total2 = 100*((int)elevatorString[i]-48);
                    int sum = total2+total + digit;
                    
                    current_passengers -= sum;
                    last_value = elevatorString[i];
                    if (current_passengers < 0) {
                        return false;
                        break;
                    }
                    continue;
                }
                if(isdigit(elevatorString[i+1])){
                    int digit = int(elevatorString[i+1] -48);
                    int total = 10*((int)elevatorString[i]-48);
                    int sum = total + digit;
                    
                    current_passengers -= sum;
                    last_value = elevatorString[i];
                    if (current_passengers < 0) {
                        return false;
                        break;
                    }
                    continue;
                    
                }
                
                else{
                    current_passengers = current_passengers - ((int)elevatorString[i] - 48);
                    last_value = elevatorString[i];
                    if (current_passengers < 0) {
                        return false;
                        break;
                    }
                    continue;
                }

            }

            last_value = elevatorString[i];
            continue;
        }
        
        if(last_value == 'C'){
            if(elevatorString[i] == 'M'){
                last_value == 'M';
                continue;
                
            }
        }
        if (elevatorString[i] == 'O'){
            if(isdigit(elevatorString[i+1])){
                return false;
                break;
            }
               if(elevatorString[i+1] == 'O'){
                   return false;
            }
            moving = 0;
            last_value = elevatorString[i];
            continue;
        }
        
        if (moving == 0){
            if(last_value == 'O'){
                if (elevatorString[i] == 'M'|| elevatorString[i] == 'O') {
                    return false;
                    break;
                }
                else if (elevatorString[i] == '+'|| elevatorString[i] == '-'){
                    last_value = elevatorString[i];
                    continue;
                }
                else if (elevatorString[i] == 'C'){
                    last_value = elevatorString[i];
                    moving =1;
                    continue;
                }
            }
            if(last_value == '+'){
                if(elevatorString[i] == 'M'){
                    return false;
                    break;
                }
                else if(elevatorString[i] == '+' || elevatorString[i] == '-' || elevatorString[i] == 'C' ||elevatorString[i] == 'O'){
                    return false;
                    break;
                }
                else if (isdigit(elevatorString[i])){
                    
                        char c = elevatorString[i];
                        int n = c;
                        current_passengers += n;
            
                    last_value = elevatorString[i];
                    continue;
                }
            }
            if(last_value == '-'){
                if(elevatorString[i] == 'M'){
                    return false;
                    break;
                }
                else if(elevatorString[i] == '+' || elevatorString[i] == '-' || elevatorString[i] == 'C' ||elevatorString[i] == 'O'){
                    return false;
                    break;
                }
                else if (isdigit(elevatorString[i])){
                    last_value = elevatorString[i];
                    char c = elevatorString[i];
                    int n = c;
                    current_passengers -= n;
                    if (current_passengers < 0) {
                        return false;
                        break;
                    }
                    continue;
                }
            }
            if(isdigit(last_value)){
                if(elevatorString[i] == 'M'){
                    return false;
                    break;
                }
                else if(elevatorString[i] == 'O'){
                    return false;
                    break;
                }
                if(elevatorString[i] == '+' || elevatorString[i] == '-' ){
                    last_value = elevatorString[i];
                    continue;
                }
                else if (isdigit(elevatorString[i])){
                    last_value = elevatorString[i];
                    continue;
                }
                if(elevatorString[i] == 'C' ){
                    moving = 1;
                    last_value = elevatorString[i];
                    continue;
                }
            }
            
        }
        if (moving == 1){
            if (elevatorString[i] == '+'||elevatorString[i] == '-'||elevatorString[i] == 'C'){
                return false;
            break;
            }
        }
        
    }
    return most_passengers;
    
}

int endingFloor(string elevatorString){
    // this code willf rist check for M, then it will check for how many digits after M, then after that it will save the value of the number into a variable called floor, and this varaible willl update until it hits the last M, then it will return that value
    if(isValidElevatorString(elevatorString) == false){
        return -1;
    }
    char ch = 'M';
    
    size_t found;
    
    found = elevatorString.find_last_of(ch);
  
    found = int(found);
    int floor;
    string s = elevatorString;
    for (int i = 0; i < elevatorString.size(); i++){
        if (elevatorString[i] == elevatorString[found]){
            if(isdigit(elevatorString[i+1])){
                if(isdigit(elevatorString[i+1])&& isdigit(elevatorString[i+2])){
                    if(isdigit(elevatorString[i+1])&& isdigit(elevatorString[i+2])&& isdigit(elevatorString[i+3])){
                        int digit;
                        digit = 100*((int)elevatorString[i+1] -48);
                        int digit2 = 10*((int)elevatorString[i+2] -48);
                        int digit3 = (int)elevatorString[i+3] -48;
                        floor = digit + digit2 + digit3;
                    }
                    else{
                        int digit;
                    digit = 10*((int)elevatorString[i+1] -48);
                    int digit2 = (int)elevatorString[i+2] -48;
                    floor = digit + digit2;
                    }
                }
                else{
                floor= (int)elevatorString[i+1] -48;
                }
             }
        }
    }
    return floor;
}

int highestFloor(string elevatorString){
    // this code willf rist check for M, then it will check for how many digits after M, then after that it will save the value of the number into a variable called floor, and this varaible willl update until it hits the last M, then it will return that value, but instead of just returning the floor value, it will return another varaible taht will only change if and only if the current floor is greater than the other.
    if(isValidElevatorString(elevatorString) == false){
        return -1;
    }
    int previousFloor = 0;
    
    int currentFloor = 0;
    for (int i = 0; i < elevatorString.size(); i++){
        if (elevatorString[i] == 'M'){
            
            if(isdigit(elevatorString[i+1])){
                if(isdigit(elevatorString[i+1])&& isdigit(elevatorString[i+2])){
                    if(isdigit(elevatorString[i+1])&& isdigit(elevatorString[i+2])&& isdigit(elevatorString[i+3])){
                        int digit;
                        digit = 100*((int)elevatorString[i+1] -48);
                        int digit2 = 10*((int)elevatorString[i+2] -48);
                        int digit3 = (int)elevatorString[i+3] -48;
                        currentFloor = digit + digit2 + digit3;
                        if(previousFloor < currentFloor){
                            previousFloor = currentFloor;
                        }
                        continue;
                    }
                    else{
                        int digit;
                    digit = 10*((int)elevatorString[i+1] -48);
                    int digit2 = (int)elevatorString[i+2] -48;
                        currentFloor = digit + digit2;
                        if(previousFloor < currentFloor){
                            previousFloor = currentFloor;
                        }
                        continue;
                    }
                }
                else{
                    currentFloor= (int)elevatorString[i+1] -48;
                    if(previousFloor < currentFloor){
                        previousFloor = currentFloor;
                    }
                    continue;
                }
             }
        }
    }
    return previousFloor;
}



int main(){
    string x;
    
    cout<<"input elevator string"<<endl;
    
    cin>> x;
    
    
            
        
    
        cout<<boolalpha;
        cout<< "isvalidelevatorString returns "<< isValidElevatorString(x)<<endl;
        cout<<boolalpha;
        cout << "doorsOpen(x) returns " << doorsOpen(x)<< endl;
        cout<<"endingPassengers(x) returns "<<endingPassengers(x)<<endl;
        cout<<"mostPassengers(x) returns "<<mostPassengers(x)<<endl;
        cout<<"endingFloor(x) returns "<<endingFloor(x)<<endl;
        cout<<"highestFloor(x) returns "<< highestFloor(x)<<endl;
   
    
}




