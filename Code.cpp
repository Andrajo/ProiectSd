#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <unistd.h>

using namespace std;

ifstream input_element("first_page.in");


struct Element{

    long long current_value;
    Element *next_element;
    Element *previous_element;
    Element *after_10;
    Element *before_10;
};



class Lista{

    long long how_many_elements_are;
    Element *first_element_in_queue;
    Element *last_element_in_queue;
    Element * the_one_how_gets;
    char list_name[101];

public:

    Lista(char name_list[101]){
        this->first_element_in_queue=NULL;
        this->the_one_how_gets=NULL;
        this->last_element_in_queue=NULL;
        this->how_many_elements_are=0;
        strcpy(this->list_name,name_list);
    }

    Element* get_first_element_in_queue(){
        return first_element_in_queue;
    }

    Element* get_last_element_in_queue(){
        return last_element_in_queue;
    }

    char* get_name(){
        return list_name;
    }

    void insert_new_element(){

        cout<<"How would you like to insert your new variables?\n1) Manually from console;\n2) Auto from a folder;\nYour variant:";
        int mode_for_inserting;

        while(true) {

            while (true) {
                if (cin >> mode_for_inserting)
                    break;
                cin.clear();
                cin.ignore();
                cout << "\nInvalid type for the input;\nPlease input a integer!\n\nYour command will be:";
            }

            int correct_value_for_inserting=1;

            if(mode_for_inserting!=1 and mode_for_inserting!=2)
                correct_value_for_inserting=0;
            if(correct_value_for_inserting==1)
                break;
        }

        if(mode_for_inserting==1) {

            int how_many_did_you_add = 0;
            cout << "\nInput a string value to stop inserting numbers!\n";

            while (true) {

                long long value_of_the_new_element;
                cout << "Please insert the value of the element you want to add:";
                int is_it_over = 0;

                while (true) {
                    if (cin >> value_of_the_new_element)
                        break;
                    else {
                        is_it_over = 1;
                        cin.clear();
                        cin.ignore();
                        cout << "\nThe adding session is over\n";
                        break;
                    }
                }

                if (is_it_over == 1)
                    break;

                cout << '\n';

                Element *new_element = new Element;

                new_element->current_value = value_of_the_new_element;
                new_element->next_element = NULL;
                new_element->previous_element=NULL;
                new_element->after_10=NULL;
                new_element->before_10=NULL;


                if (how_many_elements_are == 0) {

                    first_element_in_queue = new_element;
                    the_one_how_gets = new_element;
                }

                if (how_many_elements_are == 1){

                    if(new_element->current_value>first_element_in_queue->current_value){
                        last_element_in_queue=new_element;
                        first_element_in_queue->next_element=new_element;
                        new_element->previous_element=first_element_in_queue;
                    }
                    else{
                        first_element_in_queue->previous_element=new_element;
                        new_element->next_element=first_element_in_queue;
                        last_element_in_queue=first_element_in_queue;
                        first_element_in_queue=new_element;
                    }
                }

                if (how_many_elements_are > 1){

                    if(new_element->current_value>first_element_in_queue->current_value and new_element->current_value<last_element_in_queue->current_value) {

                        Element *element_for_verifying = first_element_in_queue;

                        while (element_for_verifying->next_element != NULL) {
                            if (new_element->current_value < element_for_verifying->current_value) {
                                break;
                            }
                            element_for_verifying=element_for_verifying->next_element;
                        }

                        Element *previous_element_after_verifying = element_for_verifying->previous_element;
                        previous_element_after_verifying->next_element = new_element;
                        element_for_verifying->previous_element = new_element;
                        new_element->previous_element = previous_element_after_verifying;
                        new_element->next_element = element_for_verifying;

                    }


                    if(new_element->current_value>=last_element_in_queue->current_value){
                        new_element->previous_element=last_element_in_queue;
                        last_element_in_queue->next_element=new_element;
                        last_element_in_queue = new_element;

                    }
                    else
                    if(new_element->current_value<=first_element_in_queue->current_value){
                        new_element->next_element=first_element_in_queue;
                        first_element_in_queue->previous_element=new_element;
                        first_element_in_queue=new_element;

                    }
                }

                how_many_elements_are++;
                if(how_many_elements_are%10==0){
                    the_one_how_gets->after_10=new_element;
                    new_element->before_10=the_one_how_gets;
                    the_one_how_gets=new_element;
                }
                how_many_did_you_add++;
            }

            cout << "\nYou added " << how_many_did_you_add << " more elements to the list!\n";
        }

        if(mode_for_inserting==2){

            long long value_of_the_new_element,how_many_did_you_add=0;

            while(!input_element.eof()){

                while (true) {
                    if (input_element >> value_of_the_new_element)
                        break;
                    input_element.clear();
                    input_element.ignore();
                    break;
                }

                Element *new_element = new Element;

                new_element->current_value = value_of_the_new_element;
                new_element->next_element = NULL;
                new_element->previous_element=NULL;
                new_element->after_10=NULL;
                new_element->before_10=NULL;


                if (how_many_elements_are == 0) {

                    first_element_in_queue = new_element;
                    the_one_how_gets = new_element;
                }

                if (how_many_elements_are == 1){

                    if(new_element->current_value>first_element_in_queue->current_value){
                        last_element_in_queue=new_element;
                        first_element_in_queue->next_element=new_element;
                        new_element->previous_element=first_element_in_queue;
                    }
                    else{
                        first_element_in_queue->previous_element=new_element;
                        new_element->next_element=first_element_in_queue;
                        last_element_in_queue=first_element_in_queue;
                        first_element_in_queue=new_element;
                    }
                }

                if (how_many_elements_are > 1){

                    if(new_element->current_value>first_element_in_queue->current_value and new_element->current_value<last_element_in_queue->current_value) {

                        Element *element_for_verifying = first_element_in_queue;

                        while (element_for_verifying->next_element != NULL) {
                            if (new_element->current_value < element_for_verifying->current_value) {
                                break;
                            }
                            element_for_verifying=element_for_verifying->next_element;
                        }

                        Element *previous_element_after_verifying = element_for_verifying->previous_element;
                        previous_element_after_verifying->next_element = new_element;
                        element_for_verifying->previous_element = new_element;
                        new_element->previous_element = previous_element_after_verifying;
                        new_element->next_element = element_for_verifying;

                    }


                    if(new_element->current_value>=last_element_in_queue->current_value){
                        new_element->previous_element=last_element_in_queue;
                        last_element_in_queue->next_element=new_element;
                        last_element_in_queue = new_element;

                    }
                    else
                        if(new_element->current_value<=first_element_in_queue->current_value){
                            new_element->next_element=first_element_in_queue;
                            first_element_in_queue->previous_element=new_element;
                            first_element_in_queue=new_element;

                        }
                }

                if(how_many_elements_are%10==0){
                    the_one_how_gets->after_10=new_element;
                    new_element->before_10=the_one_how_gets;
                    the_one_how_gets=new_element;
                }

                how_many_elements_are++;
                how_many_did_you_add++;
            }
            cout<<"You added "<<how_many_did_you_add<<" more elements to the current list!\n";
        }
    }

    void delete_element(long long element){

        if(how_many_elements_are>0){

            Element *current_element = first_element_in_queue;
            int in_queue=0;

            while(current_element->next_element!=NULL){
                if(current_element->after_10!=NULL and current_element->after_10->current_value<=element) {
                    current_element=current_element->after_10;
                    cout<<"KEK ";
                }
                else {
                    if (current_element->current_value == element) {
                        in_queue = 1;
                        break;
                    }
                    current_element = current_element->next_element;
                }
            }

            if(in_queue) {
                if(current_element->previous_element!=NULL)
                    current_element->previous_element->next_element = current_element->next_element;
                if(current_element->next_element!=NULL)
                    current_element->next_element->previous_element = current_element->previous_element;
            }
            if(in_queue==1)
                cout<<"Element deleted successfully";
            else
                cout<<"The element you want to delete is not in the list";
        }
        else{
            cout<<"There are no elements\n";
        }
    }

    void the_smallest_element(){

        if(how_many_elements_are>0)
            cout<<first_element_in_queue->current_value;
        else
            cout<<"There are no elements\n";
    }

    void the_biggest_element(){
        if(how_many_elements_are>0)
            cout<<last_element_in_queue->current_value;
        else
            cout<<"There are no elements\n";
    }

    void the_next_element(long long element){
        if(how_many_elements_are>0){

            Element *the_smallest_big;
            Element *current_element=first_element_in_queue;
            bool was_found_one=false;

            while(current_element->next_element!=NULL){

                if(current_element->after_10!=NULL and current_element->after_10->current_value<=element) {
                    current_element=current_element->after_10;
                }
                else {

                    if (current_element->current_value > element) {
                        the_smallest_big = current_element;
                        was_found_one = true;
                        break;
                    }

                    current_element = current_element->next_element;
                }
            }

            if(was_found_one == false)
                printf("There was no element bigger than %d",(element));
            else
                cout<<the_smallest_big->current_value;
        }
        else{
            cout<<"There are no elements\n";
        }
    }

    void the_element_before(long long element){

        if(how_many_elements_are>0){

            Element *the_biggest_small,*current_element=last_element_in_queue;
            bool was_found_one=false;

            while(current_element->previous_element!=NULL) {

                if(current_element->before_10!=NULL and current_element->before_10->current_value>=element) {
                    current_element=current_element->before_10;
                }
                else {

                    if (current_element->current_value < element) {
                        the_biggest_small = current_element;
                        was_found_one = true;
                        break;
                    }

                    current_element = current_element->previous_element;
                }
            }

            if(was_found_one == false)
                printf("There was no element smaller than %d",(element));
            else
                cout<<the_biggest_small->current_value;
        }
        else{
            cout<<"There are no elements\n";
        }

    }

    void the_k_element(long long k){

        if(k>how_many_elements_are/2 and k!=how_many_elements_are){

            long long current_position=how_many_elements_are;
            Element *current_element=last_element_in_queue;

            while(current_position>k){
                current_position--;
                current_element=current_element->previous_element;
            }

            cout<<current_element->current_value;
        }

        if(k<=how_many_elements_are/2 and k!=1){

            long long current_position=1;
            Element *current_element=first_element_in_queue;

            while(current_position<k){
                current_position++;
                current_element=current_element->next_element;
            }

            cout<<current_element->current_value;
        }

        if(k==how_many_elements_are){
            cout<<last_element_in_queue->current_value;
        }

        if(k==1){
            cout<<first_element_in_queue->current_value;
        }

        if(k>how_many_elements_are){
            cout<<"There are not enough elements in the list\n";
        }
    }

    long long get_how_many_elements(){
        return how_many_elements_are;
    }

    bool is_in_queue(long long element){

        Element *current_element = first_element_in_queue;

        while (current_element != NULL) {
            if(current_element->after_10!=NULL and current_element->after_10->current_value<=element) {
                current_element=current_element->after_10;
            }
            else {
                if (current_element->current_value == element) {
                    cout << "Is in queue\n";
                    return true;
                }
                current_element = current_element->next_element;
            }
        }

        cout << "Is doesn't appear in the queue\n";
        return false;
    }

    void showcase_elements(Element *element){

        if(how_many_elements_are>0){
            printf("%lld ", (element->current_value));
            if (element->next_element != NULL)
                showcase_elements(element->next_element);
        }
        else{
            cout<<"There are no elements";
        }
    }
};

vector<Lista> data_for_program;
long long how_much_data;

class menu{
public:

    void command_1(){

        char name_list[101];

        while(true){

            cout<<"Name the list:";
            cin>>name_list;
            int name_is_ok=1;

            for(long long i=0;i<how_much_data;i++){
                if(strcmp(data_for_program[i].get_name(),name_list)==0){
                    name_is_ok=0;
                    cout<<"\nName already in use\n";
                    break;
                }
            }

            if(name_is_ok==1)
                break;
        }
        Lista A(name_list);
        data_for_program.push_back(A);
        how_much_data++;
    }

    void command_2(Lista &lista, Lista &lista2){

        if(strcmp(lista.get_name(),lista2.get_name())==0)
            cout<<"You are already in this list!\n";
        else{
            swap(lista, lista2);
            cout<<"You have successfully transferred to "<<lista.get_name();
        }
    }

    void command_3(Lista &lista){
        lista.insert_new_element();
    }

    void command_4(Lista &lista){
        lista.the_smallest_element();
    }

    void command_5(Lista &lista){
        lista.the_biggest_element();
    }

    void command_6(Lista &lista){
        lista.showcase_elements(lista.get_first_element_in_queue());
    }

    void command_7(Lista &lista,long long  number){
        lista.is_in_queue(number);
    }

    void command_8(Lista &lista,long long  number){
        lista.delete_element(number);
    }

    void command_9(Lista &lista,long long  number){
        lista.the_k_element(number);
    }

    void command_10(Lista &lista,long long  number){
        lista.the_next_element(number);
    }

    void command_11(Lista &lista,long long number){
        lista.the_element_before(number);
    }

    void command_12(Lista &lista){
        cout<<lista.get_name();
        cout<<"\n"<<&lista;
    }

    void command_13(Lista &lista){
        cout<<lista.get_how_many_elements();
    }
};

void presentation(){
    cout<<"""\n"
    " 1. Create list\n"
    " 2. Change current list\n"
    " 3. Insert element\n"
    " 4. Minim of the current list\n"
    " 5. Maxim of the current list\n"
    " 6. Showcase elements of the current list\n"
    " 7. Is in the current list?\n"
    " 8. Delete from the current list\n"
    " 9. The K element\n"
    " 10. Next element from x\n"
    " 11. Previous element from x\n"
    " 12. Name and memory place of the current list\n"
    " 13. How many elements are in the current list\n"
    " 0. Exit""";
    cout<<"\nInput a command:";
}

int command;

int main(){

    menu Meniu;
    Lista prima_lista((char*)"prima lista");
    Lista current_list=prima_lista;
    data_for_program.push_back(prima_lista);
    how_much_data++;
    long long number;

    while(true){

        presentation();

        while(true){
            if(cin>>command)
                break;
            cin.clear();
            cin.ignore();
            cout<<"\nInvalid type for the input;\nPlease input a integer!\n\nYour command will be:";
        }

        if(command==0){
            cout<<"Bye!";
            break;
        }

        if(command==1) {
            Meniu.command_1();
        }

        if(command==2) {

            cout<<"You are in "<<current_list.get_name()<<"\n";
            int input_position_for_new_list=-1;

            for(long long i=1;i<how_much_data;i++){
                cout<<i<<". "<<data_for_program[i].get_name()<<'\n';
            }

            while(true){

                cin>>input_position_for_new_list;
                if(input_position_for_new_list>0 and input_position_for_new_list<=how_much_data)
                    break;
                else
                    cout<<"Invalid position, please insert a number of a list:";
            }

            Meniu.command_2(current_list,data_for_program[input_position_for_new_list]);
        }

        if(command==3){
            Meniu.command_3(current_list);
        }

        if(command==4) {
            Meniu.command_4(current_list);
        }

        if(command==5){
            Meniu.command_5(current_list);
        }

        if(command==6){
            Meniu.command_6(current_list);
        }

        if(command==7){
            if(current_list.get_how_many_elements()>0){

                cout<<"Input a number:";

                while(true){
                    if(cin>>number)
                        break;
                    cin.clear();
                    cin.ignore();
                    cout<<"\nInvalid type for the input;\nPlease input a integer!\n\nYour number will be:";
                }

                Meniu.command_7(current_list,number);
            }
            else{
                cout<<"There is nothing";
            }
        }

        if(command==8){
            if (current_list.get_how_many_elements() > 0){

                cout << "Input a number:";

                while(true){
                    if(cin>>number)
                        break;
                    cin.clear();
                    cin.ignore();
                    cout<<"\nInvalid type for the input;\nPlease input a integer!\n\nYour number will be:";
                }

                Meniu.command_8(current_list, number);
            }
            else{
                cout<<"There is nothing";
            }
        }

        if(command==9){
            if(current_list.get_how_many_elements()>0){

                cout << "Input a number:";

                while(true){
                    if(cin>>number)
                        break;
                    cin.clear();
                    cin.ignore();
                    cout<<"\nInvalid type for the input;\nPlease input a integer!\n\nYour number will be:";
                }

                Meniu.command_9(current_list, number);
            }
            else{
                cout<<"There is nothing";
            }
        }

        if(command==10){
            if(current_list.get_how_many_elements()>0){

                cout << "Input a number:";

                while(true){
                    if(cin>>number)
                        break;
                    cin.clear();
                    cin.ignore();
                    cout<<"\nInvalid type for the input;\nPlease input a integer!\n\nYour number will be:";
                }

                Meniu.command_10(current_list, number);
            }
            else{
                cout<<"There is nothing";
            }
        }

        if(command==11){
            if(current_list.get_how_many_elements()>0){
                cout<<"Input a number:";
                while(true){
                    if(cin>>number)
                        break;
                    cin.clear();
                    cin.ignore();
                    cout<<"\nInvalid type for the input;\nPlease input a integer!\n\nYour number will be:";
                }

                Meniu.command_11(current_list,number);
            }
            else{
                cout<<"There is nothing";
            }
        }

        if(command==12) {
            Meniu.command_12(current_list);
        }

        if(command==13) {
            Meniu.command_13(current_list);
        }
        if(command>13 or command<0) {
            cout << "Invalid option";
        }

        //sleep(4);
        //system("clear");
    }
}
