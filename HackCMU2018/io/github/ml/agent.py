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
        self.model.fit(data, None, epochs=epochs, batch_size=100)
        if save:
            self.save_model()
    
    def get_model(self):
        return self.model
    
    def mutate_model(self, mutations):
        print (mutations)