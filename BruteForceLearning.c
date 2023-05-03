#include "BruteForceLearning.h"

void brute_force_learning(double input, double weight, double expected_val, double step_amt, long epochs){
    
    double prediction = 0.0,
            error  = 0.0;
    // Get the first value of iterations
    long steps = epochs;
    do{
        printf("For Epoch: %ld\n", steps-epochs);
        // make a prediction
        prediction = input * weight;
        // Compute the error of the prediction
        error = powf(expected_val-prediction, 2);
        // Print current prediction and value
        printf("Prediction: %lf\tError: %lf\n", prediction, error);

        // get the optimal direction for learning
        double up_prediction = input * (weight+step_amt);
        double up_error = powf(expected_val-up_prediction, 2);

        double down_prediction = input* (weight-step_amt);
        double down_error = powf(expected_val-down_prediction, 2);

        if(up_error < down_error){
            weight += step_amt;
        }
        else if(up_error > down_error){
            weight -= step_amt;
        }
    }
    while((--epochs) > -1);

    printf("Done!\nFinalized Values\tPrediction = %lf\tError: %lf\n", prediction, error);
}