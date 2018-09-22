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
        print ("Got called")
        num_of_files = len(data)
        shaped_input = [0 for i in range(num_of_files)]
        shaped_output = [0 for i in range(num_of_files)]
        for file_num in range(num_of_files):
            num_of_errors = data[file_num][0]
            lines = tf.reshape(np.asarray(data[file_num][2]), [1, 2500])
            lines = tf.strings.to_hash_bucket(lines, num_buckets=98317)
            errors = data[file_num][1]
            line_errors = [0 for i in range(2500)]
            for i in errors:
                line_errors[i] = 1

            line_errors = tf.reshape(line_errors, [1, 2500])
            
            shaped_input[file_num] = lines
            shaped_output[file_num] = errors
        
        self.model.compile(optimizer=tf.train.GradientDescentOptimizer(0.5), 
                           loss="mse", 
                           metrics=["mae"])
        
        self.model.fit(shaped_input,
                       shaped_output,
                       epochs=25,
                       steps_per_epoch=25)
            
        if save:
            self.save_model()
    
        #print ("File " + str(file_num))
        
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
            
            
