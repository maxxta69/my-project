// #include <stdio.h>

// void incrementor(int *a)
// {
//     (*a)++;
//     printf("The new value of a = %d\n", *a);
// }

// void ArrayPrinter(int *a, int len){
//     for (int i = 0; i < len; i++){
//         printf("x[%d] = %d\n", i, a[i]);
//     }
// }

// void ArrayPointerII(int a[], int len){
//     for (int i = 0; i < len; i++){
//         printf("x[%d] = %d\n", i, a[i]);
//     }
// }

// void array_doubler(int *a, int len){
//     for (int i = 0; i < len; i++){
//         a[i] *= 2;
//     }
// }

// void array_filler(int* a, int len){
//     for (int i = 0; i < len; i++)
//     {
//         *(a + i) = i + 1;
//     }
// }

// struct Car {
//     int speed;
//     float price;
//     char *name;
// };

// void create_car(struct Car *car, char* name, int speed, float price){
//     car->name = name;
//     car->speed = speed;
//     car->price = price;
// }

// void print_car(struct Car *car){
//     printf("Car name: %s\n", car->name);
//     printf("Car price: %f\n", car->price);
//     printf("Car speed: %d\n", car->speed);
// }

// #pragma pack(1)
// struct WithoutPadding{
//     char a;
//     int b;
//     char c;
// };
// #pragma pack()

// struct WithPadding{
//     char a;
//     int b;
//     char c;
// };

// int main(void){

//     printf("Without Packing: %lu\n", sizeof(struct WithoutPadding));

//     printf("With Packing: %lu\n", sizeof(struct WithPadding));

//     return 0;
// }


// #include <stdio.h>
// #include <string.h>
// #include <stdbool.h>

// struct Student{
//     int ID;
//     char name[50];
//     float GPA;
// };

// void add_student(struct Student* student, int ID, char* name, float GPA){
//     student->ID = ID;
//     strcpy(student->name, name);
//     student->GPA = GPA;
// }

// void display_all_students(struct Student* student){
//     printf("Name: %s\n", student->name);
//     printf("ID: %d\n", student->ID);
//     printf("GPA: %f\n\n", student->GPA);
// }

// void find_by_id(struct Student* student, int ID, int No_of_stdudents){
//     bool found = false;
//     for (int i = 0; i < No_of_stdudents; i++){
//         if(student[i].ID == ID){
//             printf("Student found:\n");
//             printf("Name: %s\n", student[i].name);
//             printf("ID: %d\n", student[i].ID);
//             printf("GPA: %f\n", student[i].GPA);
//             found = true;
//             break;
//         }
//     }
//     if(!found){
//         printf("Student not found!\n");
//     }

// }

// void find_by_name(struct Student* student, char* name, int No_of_students){
//     bool found = false;
//     for (int i = 0; i < No_of_students; i++){
//         if(strstr(student[i].name, name)){
//             printf("Student found:\n");
//             printf("Name: %s\n", student[i].name);
//             printf("ID: %d\n", student[i].ID);
//             printf("GPA: %f\n", student[i].GPA);
//             found = true;
//             break;
//         }
//     }
//     if(!found){
//         printf("Student not found!\n");
//     }

// }

// int main(void){

//     struct Student student[3] = {0};

//     int count = 3;
//     add_student(&student[0], 101, "Alice", 3.85);
//     add_student(&student[1], 102, "Bob", 3.45);
//     add_student(&student[2], 103, "Charlie", 3.92);

//     // find_by_id(student, 102, count);

//     char name[50];

//     printf("Enter the name of the student you will like to search for: ");
//     scanf("%s", name);

//     find_by_name(student, name, count);

//     return 0;
// }

#include <stdio.h>

#pragma pack(1)
struct IPv4_Header{
    unsigned char version_ihl;
    unsigned char dscp_ecn;
    unsigned short total_length;
    unsigned short identification;
    unsigned short flags_fragment;
    unsigned char ttl;
    unsigned char protocol;
    unsigned short checksum;
    unsigned int src_ip;
    unsigned int dst_ip;
};

void print_ipv4_header(struct IPv4_Header *header){
    unsigned char src_byte1 = (header->src_ip >> 24) & 0Xff;
    unsigned char src_byte2 = (header->src_ip >> 16) & 0xff;
    unsigned char src_byte3 = (header->src_ip >> 8) & 0xff;
    unsigned char src_byte4 = header->src_ip & 0xff;

    printf("Source IP: %d.%d.%d.%d\n", src_byte1, src_byte2, src_byte3, src_byte4);

    unsigned char des_byte1 = (header->dst_ip >> 24) & 0xff;
    unsigned char des_byte2 = (header->dst_ip >> 16) & 0xff;
    unsigned char des_byte3 = (header->dst_ip >> 8) & 0xff;
    unsigned char des_byte4 = header->dst_ip & 0xff;

    printf("Destination IP: %d.%d.%d.%d\n", des_byte1, des_byte2, des_byte3, des_byte4);

    if(header->protocol == 6){
        printf("Protocol: TCP(6)\n");
    }
    else if(header->protocol == 1){
        printf("Protocol: ICMP(1)\n");
    }
    else if(header->protocol == 17){
        printf("Protocol: UDP(17)\n");
    }
    else{
        printf("Protocol: %d\n", header->protocol);
    }

    printf("TTL: %d\n", header->ttl);
    printf("Total Length: %d\n", header->total_length);
    printf("Checksum: 0x%04x\n", header->checksum);
}
#pragma pack()