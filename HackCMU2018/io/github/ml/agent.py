import tensorflow as tf
from numpy import random
import numpy as np
from tensorflow import keras
import os


class Agent:
    
    def __init__(self, src, agent_init):
        self.src = src
        self.model = keras.Sequential()
        if os.path.isfile(self.src):
            # Load model
            self.model = keras.models.load_model(self.src)
        else:
            # Generate model
            # agent_init[0] = number of input nodes for first layer : int
            # agent_init[1] = list of outputs for all layers : int list
            for i in range(len(agent_init[1])):
                if i == 0:
                    self.model.add(keras.layers.Dense(agent_init[1][i], 
                                                      input_shape=(2500,),
                                                      activation="sigmoid"))
                else:
                    self.model.add(keras.layers.Dense(agent_init[1][i],
                                                      activation="sigmoid"))
        
        
    def save_model(self):
        self.model.save(self.src)
        
    def load_model(self):
        if os.path.isfile(self.src):
            self.model = keras.models.load_model(self.src)
        
    def run_model(self, data, epochs, save=False):
        num_of_files = len(data)
        for file_num in range(num_of_files):
            num_of_errors = data[file_num][0]
            lines = tf.reshape(np.asarray(data[file_num][2]), [1, 2500])
            lines = tf.strings.to_number(lines, out_type=tf.float64)
            errors = data[file_num][1]
            line_errors = [0 for i in range(2500)]
            for i in range(len(errors)):
                line_errors[errors[i]] = 1

            line_errors = tf.reshape(line_errors, [1, 2500])
            
        
            self.model.compile(optimizer=tf.train.GradientDescentOptimizer(0.2), 
                                loss="mse", 
                                metrics=["mae"])
        
            self.model.fit(lines,
                           line_errors,
                           epochs=epochs,
                           steps_per_epoch=50)
            
            if save:
                self.save_model()
    
            print ("File " + str(file_num))
        
        return 1
    
    def get_model(self):
        return self.model
    
    def set_model(self, m):
        self.model = m
    
    def mutate_model(self, mutation):
        weights = self.model.get_weights()
        for outer_weights in weights:
            for inner_weight in outer_weights:
                inner_weight = inner_weight * (1 + (2 * (.5- .5) * mutation))
            
    def run_prediction(self, data):
        print ("Predicting")
        num_of_errors = data[0][0]
        lines = tf.reshape(np.asarray(data[0][2]), [1, 2500])
        lines = tf.strings.to_hash_bucket(lines, num_buckets=98317)
        errors = data[0][1]
        line_errors = [0 for i in range(2500)]
        for i in range(len(errors)):
            line_errors[errors[i]] = 1
        
        outputs = self.model.predict(lines, steps=50).tolist()
        sum = 0
        correct_counter = 0
        incorrect_counter = 0
        no_op_counter = 0
        for i in range(2500):
            #print ("Line " + str(i) + ": " + str(line_errors[i]) 
            # + "; result: " + str(outputs[49][i]))
            actual_res = line_errors[i]
            pred_res = outputs[49][i]
            if pred_res < 0.2 and actual_res == 0:
                correct_counter += 1
            elif pred_res < 0.2:
                incorrect_counter += 1
            elif pred_res > 0.8 and actual_res == 1:
                correct_counter += 1
            elif pred_res > 0.8:
                incorrect_counter += 1
            else:
                no_op_counter += 1
            sum = sum + outputs[49][i] if outputs[49][i] > .1 else sum
                
        print ("Correct: " + str(correct_counter))
        print ("Incorrect: " + str(incorrect_counter))
        print ("No operation: " + str(no_op_counter))
        print ("sum: " + str(sum))