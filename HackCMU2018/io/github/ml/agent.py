import tensorflow as tf
from tensorflow import keras
import os


class Agent:
    
    def __init__(self, src, agent_init):
        self.src = src
        self.model = keras.Sequential()
        if os.path.isfile(self.source):
            # Load model
            self.model.load_model(self.source)
        else:
            # Generate model
            # agent_init[0] = number of input nodes for first layer : int
            # agent_init[1] = list of outputs for all layers : int list
            for i in range(len(agent_init[1])):
                if i == 0:
                    self.model.add(keras.layers.Dense(agent_init[1][i], input_shape=agent_init[0]))
                else:
                    self.model.add(keras.layers.Dense(agent_init[1][i]))
        
        
    def save_model(self):
        self.model.save(self.src)
        
    def load_model(self):
        self.model.load_model(self.src)
        
    def run_model(self, data, epochs, save=False):
        num_of_files = len(data)
        for file_num in range(num_of_files):
            num_of_errors = data[file_num][0]
            line_errors = data[file_num][1]
            lines = data[file][2]
        
            self.model.compile(optimizer=tf.train.GradientDescentOptimizer, 
                                loss="mse", 
                                metrics=["mae"])
        
            self.model.fit(lines,
                           line_errors,
                           epochs=epochs)
            
            if save:
                self.save_model()
    
            print ("File " + file_num)
    
    def get_model(self):
        return self.model
    
    def set_model(self, m):
        self.model = m
    
    def mutate_model(self, mutations):
        print (mutations)
            
            