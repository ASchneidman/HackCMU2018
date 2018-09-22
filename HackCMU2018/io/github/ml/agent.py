import tensorflow as tf
import numpy as np
from tensorflow import keras
import os


class Agent:
    
    def __init__(self, src):
        self.src = src
        self.model = keras.Sequential()
        if os.path.isfile(self.src):
            # Load model
            self.model = keras.models.load_model(self.src)
        else:
            # Generate model
            for i in range(6):
                if i == 0:
                    self.model.add(keras.layers.Dense(1000, 
                                                      input_shape=(80000, ),
                                                      activation="sigmoid"))
                elif i == 5:
                    self.model.add(keras.layers.Dense(1000,
                                                      activation="sigmoid"))
                else:
                    self.model.add(keras.layers.Dense(1000,
                                                      activation="sigmoid"))
        
        
    def save_model(self):
        self.model.save(self.src)
        
    def load_model(self):
        if os.path.isfile(self.src):
            self.model = keras.models.load_model(self.src)
        
    def run_model(self, data, epochs, save=False):
        print ("Training")
        num_of_files = len(data)
        all_lines = []
        all_line_errors = []
        all_num_errors = []
        for i in range(num_of_files):
            flat_list = [item for sublist in data[i][2] for item in sublist]
            all_lines.append(flat_list)
            all_num_errors.append(data[i][0])
            errors = data[i][1]
            line_errors = [0 for j in range(1000)]
            for j in range(len(errors)):
                if errors[j] < 1000:
                    line_errors[errors[j]] = 1
                
            all_line_errors.append(line_errors)
            
        all_lines = np.asarray(all_lines)
        all_line_errors = np.asarray(all_line_errors)
        
        self.model.compile(optimizer=tf.train.GradientDescentOptimizer(0.2), 
                            loss="mse", 
                            metrics=["mae"])
        
        self.model.fit(all_lines,
                        all_line_errors,
                        epochs=epochs,
                        batch_size=5)
            
        if save:
            self.save_model()
        
        return 1
    
    def get_model(self):
        return self.model
    
    def set_model(self, m):
        self.model = m
            
    def run_prediction(self, data):
        print ("Predicting")
        all_lines = []
        all_line_errors = []
        all_num_errors = []

        flat_list = [item for sublist in data[0][2] for item in sublist]
        all_lines.append(flat_list)
        all_num_errors.append(data[0][0])
        errors = data[0][1]
        line_errors = [0 for j in range(1000)]
        for j in range(len(errors)):
            line_errors[errors[j]] = 1
                
        all_line_errors.append(line_errors)
            
        all_lines = np.asarray(all_lines)
        all_line_errors = np.asarray(all_line_errors)
        
        outputs = self.model.predict(all_lines, steps=50).tolist()
        
        return outputs
                
        #print ("Correct: " + str(correct_counter))
        #print ("Incorrect: " + str(incorrect_counter))
        #print ("No operation: " + str(no_op_counter))
        #print ("sum: " + str(val_sum))
