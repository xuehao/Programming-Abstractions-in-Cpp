/**
 * File: CheckoutLine.cpp
 * ----------------------
 * This program simulates a checkout line, such as one you
 * might encounter in a grocery store. Customers arrive at
 * the checkout stand and get in line. Those customers wait
 * in the line until the cashier is free, at which point
 * they are served and occupy the cashier for some period
 * of time. After the service time is complete, the cashier
 * is free to serve the next customer in the line.
 *
 * In each unit of time, up to the constant SIMULATION_TIME,
 * the following operations are performed:
 *
 * 1. Determine whether a new customer has arrived.
 * New customers arrive randomly, with a probability
 * determined by the constant ARRIVAL_PROBABILITY.
 *
 * 2. If the cashier is busy, note that the cashier has
 * spent another minute with that customer. Eventually,
 * the customer's time request is satisfied, which frees
 * the cashier.
 *
 * 3. If the cashier is free, serve the next customer in line.
 * The service time is taken to be a random period between
 * MIN_SERVICE_TIME and MAX_SERVICE_TIME.
 *
 * At the end of the simulation, the program displays the
 * simulation constants and the following computed results:
 *
 * o The number of customers served
 * o The average time spent in line
 * o The average number of people in line
 */

#include <iomanip>
#include <iostream>
#include "console.h"
#include "queue.h"
#include "random.h"
using namespace std;

/* Constants */

const double ARRIVAL_PROBABILITY = 0.05;
const int MIN_SERVICE_TIME = 5;
const int MAX_SERVICE_TIME = 15;
const int SIMULATION_TIME = 2000;

/* Function prototypes */

void runSimulation(int& nServed, int& totalWait, int& totalLength);
void printReport(int nServed, int totalWait, int totalLength);

/* Main program */

int main() {
    int nServed;
    int totalWait;
    int totalLength;
    runSimulation(nServed, totalWait, totalLength);
    printReport(nServed, totalWait, totalLength);
    return 0;
}

/**
 * Function: runSimulation
 * Usage: runSimulation();
 * -----------------------
 * This function runs the actual simulation. The number of
 * customers served, the sum of the customer waiting times,
 * and the sum of the queue length in each time step are
 * returned through the reference parameters.
 */

void runSimulation(int& nServed, int& totalWait, int& totalLength) {
    Queue<int> queue;
    int timeRemaining = 0;
    nServed = 0;
    totalWait = 0;
    totalLength = 0;
    for (int t = 0; t < SIMULATION_TIME; t++) {
        if (randomChance(ARRIVAL_PROBABILITY)) {
            queue.enqueue(t);
        }
        if (timeRemaining > 0) {
            timeRemaining--;
        } else if (!queue.isEmpty()) {
            totalWait += t - queue.dequeue();
            nServed++;
            timeRemaining = randomInteger(MIN_SERVICE_TIME, MAX_SERVICE_TIME);
        }
        totalLength += queue.size();
    }
}

/**
 * Function: printReport
 * Usage: printReport(nServed, totalWait, totalLength);
 * ----------------------------------------------------
 * This function reports the results of the simulation.
 */

void printReport(int nServed, int totalWait, int totalLength) {
    cout << "Simulation results given the following constants:" << endl;
    cout << fixed << setprecision(2);
    cout << " SIMULATION_TIME: " << setw(4) << SIMULATION_TIME << endl;
    cout << " ARRIVAL_PROBABILITY: " << setw(7) << ARRIVAL_PROBABILITY << endl;
    cout << " MIN_SERVICE_TIME: " << setw(4) << MIN_SERVICE_TIME << endl;
    cout << " MAX_SERVICE_TIME: " << setw(4) << MAX_SERVICE_TIME << endl;
    cout << endl;
    cout << "Customers served: " << setw(4) << nServed << endl;
    cout << "Average waiting time: " << setw(7) << double(totalWait) / nServed << endl;
    cout << "Average queue length: " << setw(7) << double(totalLength) / SIMULATION_TIME << endl;
}
