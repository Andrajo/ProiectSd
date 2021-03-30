#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream input_element("first_page.in");
ofstream output_element("result_page.out");
//no buna avra


struct Element
{
    int current_value;
    Element *next_element;
};

class Lista
{
    int how_many_elements_are;
    Element *first_element_in_queue;
    Element *last_element_in_queue;
    int minimum,maximum;
    char* list_name;
public:

    Lista(char* name_list)
    {
        this->how_many_elements_are=0;
        this->list_name=name_list;
    }

    Element* get_first_element_in_queue()
    {
        return first_element_in_queue;
    }

    Element* get_last_element_in_queue()
    {
        return last_element_in_queue;
    }

    char* get_name()
    {
        return list_name;
    }

    int get_how_many_elements()
    {
        return how_many_elements_are;
    }

    void insert_new_element()
    {
        int value_of_the_new_element;
        Element *new_element=new Element;
/*
    output_element<<"Please insert the value of the element you want to add:";
    input_element>>value_of_the_new_element;
    output_element<<value_of_the_new_element<<'\n';
*/
        cout<<"Please insert the value of the element you want to add:";
        cin>>value_of_the_new_element;
        cout<<'\n';

        new_element->current_value=value_of_the_new_element;
        new_element->next_element=NULL;


        if(how_many_elements_are==0)
        {
            first_element_in_queue=new_element;
            minimum=new_element->current_value;
            maximum=new_element->current_value;
        }
        else
        {
            last_element_in_queue->next_element=new_element;

            if(minimum>new_element->current_value)
            {
                minimum=new_element->current_value;
            }

            if(maximum<new_element->current_value)
            {
                maximum=new_element->current_value;
            }
        }

        last_element_in_queue=new_element;

        how_many_elements_are++;
    }

    void showcase_elements(Element *element)
    {
        printf("%d ",(element->current_value));
        if(element->next_element!=NULL)
            showcase_elements(element->next_element);
    }

    bool is_in_queue(int element)
    {
        if(how_many_elements_are>0)
        {
            Element *current_element=first_element_in_queue;
            while(current_element!=NULL)
            {
                if(current_element->current_value==element)
                {
                    cout<<"Is in queue";
                    return true;
                }
                current_element=current_element->next_element;
            }
            cout<<"Is doesn't appear in the queue";
            return false;
        }
        else
        {
            cout<<"There are no elements\n";
        }
    }

    void delete_element(int element)
    {
        if(how_many_elements_are>0)
        {
            Element *current_element = get_first_element_in_queue();
            if (is_in_queue(element)) {
                if (current_element->current_value == element) {
                    this->first_element_in_queue = first_element_in_queue->next_element;
                } else {
                    while (current_element->next_element->current_value != element and
                           current_element->next_element->next_element != NULL) {
                        current_element = current_element->next_element;
                    }
                    if (current_element->next_element->next_element != NULL) {
                        current_element->next_element = current_element->next_element->next_element;
                        how_many_elements_are--;
                    } else {
                        if (current_element->current_value == element) {
                            current_element->next_element = current_element->next_element->next_element;
                            how_many_elements_are--;
                        } else {
                            if (current_element->next_element->current_value == element) {
                                current_element->next_element = NULL;
                                last_element_in_queue = current_element;
                                how_many_elements_are--;
                            }
                        }
                    }
                }
            }
        }
        else
        {
            cout<<"There are no elements\n";
        }
    }

    void the_smallest_element()
    {
        if(how_many_elements_are>0)
        {
            cout<<minimum;
        }
        else
        {
            cout<<"There are no elements\n";
        }
    }

    void the_biggest_element()
    {
        if(how_many_elements_are>0)
        {
            cout<<maximum;
        }
        else
        {
            cout<<"There are no elements\n";
        }
    }

    void the_next_element(int element)
    {
        if(how_many_elements_are>0)
        {
            Element *the_smallest_big;
            Element *current_element=first_element_in_queue;
            bool was_found_one=false;
            while(current_element->next_element!=NULL)
            {
                if(was_found_one==true)
                {
                    if(current_element->current_value>element && current_element->current_value<the_smallest_big->current_value)
                    {
                        the_smallest_big=current_element;
                    }
                }
                else
                {
                    if(current_element->current_value>element)
                    {
                        the_smallest_big=current_element;
                        was_found_one=true;
                    }
                }
                current_element=current_element->next_element;
            }
            if(was_found_one==false)
                printf("There was no element bigger than %d",(element));
            else
                cout<<the_smallest_big->current_value;
        }
        else
        {
            cout<<"There are no elements\n";
        }
    }

    void the_element_before(int element)
    {
        if(how_many_elements_are>0)
        {
            Element *the_biggest_small,*current_element=first_element_in_queue;
            bool was_found_one=false;
            while(current_element->next_element!=NULL)
            {
                if(was_found_one==true)
                {
                    if(current_element->current_value<element && current_element->current_value>the_biggest_small->current_value)
                    {
                        the_biggest_small=current_element;
                    }
                }
                else
                {
                    if(current_element->current_value<element)
                    {
                        the_biggest_small=current_element;
                        was_found_one=true;
                    }
                }
                current_element=current_element->next_element;
            }
            if(was_found_one==false)
                printf("There was no element smaller than %d",(element));
            else
                cout<<the_biggest_small->current_value;
        }
        else
        {
            cout<<"There are no elements\n";
        }

    }

    void the_k_element(int k)
    {
        if(k<=how_many_elements_are)
        {
            int current_position=1;
            Element *current_element=first_element_in_queue;
            while(current_position<k)
            {
                current_position++;
                current_element=current_element->next_element;
            }
            cout<<current_element->current_value;
        }
        else
        {
            cout<<"There are not enough elements in the list\n";
        }
    }
};
vector<Lista> data;
int how_much_data;

class menu
{
public:
    void command_1()
    {
        char* name_list;
        cout<<"Name the list:";
        cin>>name_list;
        Lista A(name_list);
        data.push_back(A);
        how_much_data++;
    }
    Lista command_2(Lista &lista)
    {
        if(how_much_data>0)
        {
            int input_position=-1;
            for(int i=0;i<how_much_data;i++)
            {
                cout<<i<<data[i].get_name()<<'\n';
            }
            cin>>input_position;
            return data[input_position];
        }
        else
        {
            cout<<"There are no elements in this list!";
            return lista;
        }
    }
    void command_3(Lista &lista)
    {
        lista.insert_new_element();
    }
    void command_4(Lista &lista)
    {
        lista.the_smallest_element();
    }
    void command_5(Lista &lista)
    {
        lista.the_biggest_element();
    }
    void command_6(Lista &lista)
    {
        lista.showcase_elements(lista.get_first_element_in_queue());
    }
    void command_7(Lista &lista,int number)
    {
        lista.is_in_queue(number);
    }
    void command_8(Lista &lista,int number)
    {
        lista.delete_element(number);
    }
    void command_9(Lista &lista,int number)
    {
        lista.the_k_element(number);
    }
    void command_10(Lista &lista,int number)
    {
        lista.the_next_element(number);
    }
    void command_11(Lista &lista,int number)
    {
        lista.the_element_before(number);
    }
    void command_12(Lista &lista)
    {
        cout<<lista.get_name();
        cout<<"\n"<<&lista;
    }
    void command_13(Lista &lista)
    {
        cout<<lista.get_how_many_elements();
    }
};

int command;

int main()
{
    menu Meniu;
    Lista prima_lista((char*)"prima lista");
    Lista current_list=prima_lista;
    data.push_back(prima_lista);
    how_much_data++;
    int number;
    while(true)
    {
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
        cin>>command;
        if(command==0)
        {
            cout<<"Bye";
            break;
        }
        if(command==1)
        {
            Meniu.command_1();
        }
        if(command==2)
        {
            current_list=Meniu.command_2(current_list);
        }
        if(command==3)
        {
            Meniu.command_3(current_list);
        }
        if(command==4)
        {
            Meniu.command_4(current_list);
        }
        if(command==5)
        {
            Meniu.command_5(current_list);
        }
        if(command==6)
        {
            Meniu.command_6(current_list);
        }
        if(command==7)
        {
            cout<<"Input a number:";
            cin>>number;
            Meniu.command_7(current_list,number);
        }
        if(command==8)
        {
            cout<<"Input a number:";
            cin>>number;
            Meniu.command_8(current_list,number);
        }
        if(command==9)
        {
            cout<<"Input a number:";
            cin>>number;
            Meniu.command_9(current_list,number);
        }
        if(command==10)
        {
            cout<<"Input a number:";
            cin>>number;
            Meniu.command_10(current_list,number);
        }
        if(command==11)
        {
            cout<<"Input a number:";
            cin>>number;
            Meniu.command_11(current_list,number);
        }
        if(command==12)
        {
            Meniu.command_12(current_list);
        }
        if(command==13)
        {
            Meniu.command_13(current_list);
        }
    }
}
