import tensorflow as tf
import numpy as np
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
            for layer in agent_init[0]:
                self.model.add(keras.layers.Dense(layer))
        
        
    def save_model(self):
        self.model.save(self.src)
        
    def load_model(self):
        self.model.load_model(self.src)
        
    def run_model(self, data, epochs, save=False):
        num_of_files = len(data)
        for file_num in range(num_of_files):
            num_of_errors = data[file_num][0]
            error_counter = 0
            line_errors = data[file_num][1]
            lines = data[file][2]
        
            # Build the model
            # Default initial state
            input_size = len(self.model.get_weights()[0])
            num_of_layers = len(self.model.get_weights())
            state = self.StateHolder(length=input_size, agent=self, num_of_layers=num_of_layers)
        
            # Compile the model
            for i in range(len(lines)):
                # See if the line has an error
                res = 0
                for j in range(len(line_errors)):
                    if line_errors[j] == i:
                        res = 1
            
                self.model.compile(optimizer=tf.train.GradientDescentOptimizer, 
                                   loss="mse", 
                                   metrics=["mae"])
        
                state.set_string_input(lines[i], i)
        
                self.model.fit(state.get_state(),
                               res,
                               epochs=epochs,
                               callbacks=[state])
            
                outputs = self.model.get_output_at(num_of_layers - 2)
                state.set_output_input(self, outputs)
                
                output = self.model.get_output_at(num_of_layers - 1)
                if output > 0.99:
                    error_counter = error_counter + 1
                
            if save:
                self.save_model()
    
        print ("Trial " + file_num)
        print (num_of_errors)
        print (error_counter)
    
    def get_model(self):
        return self.model
    
    def set_model(self, m):
        self.model = m
    
    def mutate_model(self, mutations):
        print (mutations)
        
    class StateHolder(keras.callbacks.Callback):
        
        def __init__(self, state=None, length, agent, num_of_layers):
            if state == None:
                empty = [("", 0)]
                self.state = empty.extend(np.zeros(length - 1, dtype=float))
            else:
                self.state = state
            
            self.agent = agent
            self.num_of_layers = num_of_layers
            
        def set_state(self, state):
            self.state = state
            
        def get_state(self):
            return self.state
        
        def set_string_input(self, line, line_num):
            self.state[0] = [line, line_num]
            
        def set_output_input(self, output):
            for i in range(len(output)):
                self.state[i + 1] = output[i]
        
        def on_train_end(self, logs={}):
            self.agent.get_model().get_layer(index=(self.num_of_layers - 1))
            
            