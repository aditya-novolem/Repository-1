import random

def generate_random_number():
    # Generate a random number between 1 and 100
    return random.randint(1, 100)

if __name__ == "__main__":
    random_number = generate_random_number()
    print("Random Number:", random_number)
