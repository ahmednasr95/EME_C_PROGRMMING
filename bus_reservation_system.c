#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define PASSWORD_SIZE 5
#define NUMBER_OF_BUSES 5
#define SEATS_PER_BUS 30
#define INITIAL_ARRAY_SIZE 1
#define USER_ID 1069
#define USER_PASSWORD "EUI@5"
#define YES 'y'
#define NO 'n'
#define ID_BASE 1000

enum location
{
    DESTINATION,
    PICKUP
};

typedef struct
{
    unsigned int buses;
    unsigned int freeSeats;
    char *destination;
    char *pickup;
    unsigned int arrSize;
} route;

struct user_route
{
    unsigned int route_id;
    char destination;
    char pickup;
    unsigned int bus_number;
    unsigned int number_of_seats;
    struct user_route *nextRoute;
};
typedef struct user_route user_route;
typedef struct
{
    unsigned int id;
    unsigned int reservations;
    user_route *routePtr;
    char *password[PASSWORD_SIZE];
} user;

/* 
    Inputs: None
    Output: route struct address (route node)
    Description: Creates a route and fills it with its
    relevant data. 
*/
route *initialize_route()
{
    route *routePtr = (route *)malloc(sizeof(route));
    routePtr->buses = NUMBER_OF_BUSES;
    routePtr->freeSeats = SEATS_PER_BUS;
    routePtr->arrSize = INITIAL_ARRAY_SIZE;
    /*there can  multiple destinations in a route*/
    char *destPtr = (char *)malloc(sizeof(char) * routePtr->arrSize);
    /*there can  multiple pickup points in a route*/
    char *pickupPtr = (char *)malloc(sizeof(char) * routePtr->arrSize);
    strcpy(destPtr, "cairo");
    strcpy(pickupPtr, "aswan");
    routePtr->destination = destPtr;
    routePtr->pickup = pickupPtr;
    return routePtr;
}

/*
    Inputs: None
    Output: user struct address (user node)
    Description: Creates a route and fills it with its
    relevant data.
*/
user *initialize_user()
{
    user *userPtr = (user *)malloc(sizeof(user));
    userPtr->id = USER_ID;
    strcpy(userPtr->password, USER_PASSWORD);
    userPtr->routePtr = NULL;
    return userPtr;
}

/*
    Inputs: user struct address
    Output: None
    Description: Handles login by prompting user for username and password
    and checks input data against data stored. The function will return
    only when a valid username and password are inserted.
*/
void login(user *userPtr)
{
    unsigned int id = 0;
    char *pass[5];
    while (1)
    {
        printf("Please enter your ID and Password:\n");
        scanf(" %d %s", &id, &pass);
        if (id != (userPtr->id))
        {
            printf("Invalid ID inserted. Please try again\n");
        }
        else if (strcmp(pass, userPtr->password))
        {
            printf("Invalid password inserted. Please try again\n");
        }
        else
        {
            break;
        }
    }
    printf("Welcome user %d\n", userPtr->id);
}

/*
    Inputs: route struct address
    Output: None
    Description: Prints the available routes.
*/
void print_routes(route *routePtr)
{
    if (routePtr->arrSize == 0)
    {
        printf("No routes available\n");
        return;
    }
    printf("*********************************\n");
    printf("********Available routes:********\n");
    printf("*********************************\n");
    printf("*Pickup ------------ Destination*\n");
    for (int i = 0; i < routePtr->arrSize; ++i)
    {
        printf("*%s ------------ %s*\n", routePtr->pickup, routePtr->destination);
    }
}

/*
    Inputs: route struct address
    Output: None
    Description: Prints the available routes.
*/
bool check_string_in_array(unsigned int arrSize, char *ptr, char str[])
{
    for (int i = 0; i < arrSize; ++i)
    {
        if (strcmp(ptr[i], str))
        {
            return true;
        }
    }
    return false;
}

/*
    Inputs: user struct address, route struct address, destinaion name, pickup name, numbr of seats
    Output: route id
    Description: Creates a route, fills it with the information provided, links the route created to
    the user and generates a route id. Note that the function checks if the user has no resrvations 
    because if the user has no reserations, the route pointer has a NULL value which cannot be accessed.
*/
unsigned int add_routes(user *userPtr, route *routePtr, char destination, char pickup, unsigned int seats)
{
    user_route *user_routePtr = NULL;
    user_route *tempPtr = userPtr->routePtr;
    /*check if user had previous reservations....*/
    if (userPtr->reservations == 0)
    {
        user_routePtr = (user_route *)malloc(sizeof(user_routePtr));
        user_routePtr->bus_number = routePtr->buses;
        strcpy(user_routePtr->destination, destination);
        strcpy(user_routePtr->pickup, pickup);
        user_routePtr->number_of_seats = seats;
        user_routePtr->nextRoute = NULL;
        /*...fill in the first route address*/
        userPtr->routePtr = user_routePtr;

        return user_routePtr->route_id;
    }
    else
    {
        user_routePtr = (user_route *)malloc(sizeof(user_routePtr));
        user_routePtr->bus_number = routePtr->buses;
        strcpy(user_routePtr->destination, destination);
        strcpy(user_routePtr->pickup, pickup);
        user_routePtr->number_of_seats = seats;
        user_routePtr->route_id = ID_BASE + seats;
        user_routePtr->nextRoute = NULL;
    }
    /*otherwise run through all availabl routes till the end...*/
    while (tempPtr->nextRoute != NULL)
    {
        tempPtr = tempPtr->nextRoute;
    }
    /*...and put in the new route*/
    tempPtr->nextRoute = user_routePtr;

    return user_routePtr->route_id;
}

/*
    Inputs: user struct address, route struct address
    Output: None
    Description: Handles reserving required number of seats in a given route.
    The function executes the following steps:
    1) Prints all available routes.
    2) Prompts the user to provide a destination and a pickup location.
    3) Prompts the user to insert number of seats.
    4) Creates a route node and generates a route id which is provided to the user.
    The function checks for valid destination and pickup locations and for valid number of seats.
    The function also checks if there are available seats in selected route.
*/
void reserve(user *userPtr, route *routePtr)
{
    char *dest[5], pickup[5];
    unsigned int seats = 0, route_id = 0;
    char ack = 'n';

    print_routes(routePtr);

    while (1)
    {
        printf("Please insert destination and pickup locations:\n");
        scanf(" %s %s", &dest, &pickup);
        if (!check_string_in_array(routePtr->arrSize, routePtr->destination, dest))
        {
            printf("Invalid destination inserted. Please insert a valid destination.\n");
        }
        else if (!check_string_in_array(routePtr->arrSize, routePtr->pickup, pickup))
        {
            printf("Invalid pickup inserted. Please insert a valid pickup.\n");
        }
        else
        {
            break;
        }
    }

    while (1)
    {
        if (0 == routePtr->buses)
        {
            printf("Sorry no seats available.\n");
            break;
        }
        printf("Please insert the number of required seats:\n\
                Seats available: %d\n",
               routePtr->freeSeats);
        scanf(" %d", &seats);
        if ((0 < seats) && (routePtr->freeSeats > seats))
        {
            while (YES != ack)
            {
                printf("Are you sure you want to reserve %d seats? y/n\n", seats);
                scanf(" %c", &ack);
                if (NO == ack)
                {
                    return;
                }
            }

            route_id = add_routes(userPtr, routePtr, dest, pickup, seats);

            if (0 < routePtr->freeSeats)
            {
                (routePtr->freeSeats) -= seats;
            }
            else
            {
                --(routePtr->buses);
                (routePtr->freeSeats) -= seats;
            }
            printf("Seats reserved with reservation ID %d\n", route_id);
            return;
        }
        else
        {
            printf("Invalid number of seats inserted.\n");
        }
    }
}

/*
    Inputs: user struct address, route id
    Output: user route struct address
    Description: checks if the provided route id exists in the user's database.
    returns NULL if the id is not available.
*/
user_route *check_reservation_id(user *userPtr, unsigned int id)
{
    user_route *tempPtr = userPtr->routePtr;
    while (tempPtr->nextRoute != NULL)
    {
        if (id == tempPtr->route_id)
        {
            return tempPtr;
        }
        tempPtr = tempPtr->nextRoute;
    }
    if (id == tempPtr->route_id)
    {
        return tempPtr;
    }
    return NULL;
}

/*
    Inputs: user struct address, route id
    Output: None
    Description: removes the user route with the given id.
*/
void delete_node(user *userPtr, unsigned int id)
{
    user_route *currentPtr = userPtr->routePtr;
    user_route *previousPtr = NULL;
    while (id != currentPtr->route_id)
    {
        previousPtr = currentPtr;
        currentPtr = currentPtr->nextRoute;
    }
    previousPtr = currentPtr->nextRoute;
    free(currentPtr);
}

/*
    Inputs: user struct address, route struct address
    Output: None
    Description: Cancels a user route with provided route id.
    The function checks for valid id.
*/
void cancel(user *userPtr, route *routePtr)
{
    unsigned int id = 0, total = 0;
    char ack = 'n';
    user_route *user_routePtr = NULL;
    printf("Please insert reservation ID:\n");
    scanf(" %d", &id);
    user_routePtr = check_reservation_id(userPtr, id);
    if (user_routePtr != NULL)
    {
        while (ack != 'y')
        {
            printf("Are you sure you want to cancel reservation number %d? y/n\n", user_routePtr->route_id);
            scanf(" %c", &ack);
            if ('n' == ack)
            {
                return;
            }
        }
        routePtr->freeSeats += user_routePtr->number_of_seats;
        if (routePtr->freeSeats > 30)
        {
            ++(routePtr->buses);
            routePtr->freeSeats -= 30;
        }
        delete_node(userPtr, id);
        printf("Your reservation has been successfully canceled\n");
        return;
    }
    else
    {
        printf("Reservation ID is invalid.\n");
    }
}

void main()
{
    struct route *routePtr = NULL;
    struct user *userPtr = NULL;
    char operation = 'r';

    userPtr = initialize_user();
    routePtr = initialize_route();
    login(userPtr);
    while (operation != 'e')
    {
        printf("Please choose an operation: \n\
                (r)eserve a seat\n\
                (c)ancel a reservation\n\
                (e)xit\n");
        scanf(" %c", &operation);
        switch (operation)
        {
        case 'r':
            reserve(userPtr, routePtr);
            break;
        case 'c':
            cancel(userPtr, routePtr);
            break;
        default:
            printf("Please insert a valid character.\n");
        }
    }
}