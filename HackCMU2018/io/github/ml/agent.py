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
                                                      input_shape=(2500, 80, ),
                                                      activation="sigmoid"))
                elif i == 5:
                    self.model.add(keras.layers.Dense(2500,
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
            all_lines.extend(data[i][2])
            all_num_errors.extend(data[i][0])
            errors = data[i][1]
            line_errors = [0 for j in range(2500)]
            for j in range(len(errors)):
                line_errors[errors[j]] = 1
                
            all_line_errors.extend(line_errors)
            
        all_lines = np.reshape(all_lines, (num_of_files, 2500, 80))
        all_line_errors = np.reshape(all_line_errors, (num_of_files, 2500))
        
        self.model.compile(optimizer=tf.train.GradientDescentOptimizer(0.2), 
                            loss="mse", 
                            metrics=["mae"])
        
        self.model.fit(all_lines,
                        all_line_errors,
                        epochs=epochs,
                        steps_per_epoch=50,
                        batch_size=50)
            
        if save:
            self.save_model()
        
        return 1
    
    def get_model(self):
        return self.model
    
    def set_model(self, m):
        self.model = m
            
    def run_prediction(self, data):
        print ("Predicting")
        all_lines = data[0][2]
        all_line_errors = []
        # all_num_errors = data[0][0]

        errors = data[0][1]
        line_errors = [0 for j in range(2500)]
        for j in range(len(errors)):
            line_errors[errors[j]] = 1
                
        all_line_errors.extend(line_errors)
        
        all_lines = np.reshape(all_lines, (1, 2500, 80))
        all_line_errors = np.reshape(all_line_errors, (1, 2500))
        
        outputs = self.model.predict(all_lines, steps=50).tolist()
        val_sum = 0
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
            val_sum = sum + outputs[49][i] if outputs[49][i] > .1 else sum
                
        print ("Correct: " + str(correct_counter))
        print ("Incorrect: " + str(incorrect_counter))
        print ("No operation: " + str(no_op_counter))
        print ("sum: " + str(val_sum))