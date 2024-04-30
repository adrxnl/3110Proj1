from faker import Faker
import random
import datetime
import csv

fake = Faker()

def create_csv():
    inputNumbers = range(1, 200500)
    randomizedlist = random.sample(inputNumbers, 200000)
    with open('fakePersonData.csv', 'w', newline='') as file:
        writer = csv.writer(file)
        i = 0  # Start from 0 since list indices are zero-based
        mindate = datetime.datetime(1990, 1, 1)
        maxdate = datetime.datetime(2018, 12, 30)
        while i < 100000:  # Corrected the loop condition
            writer.writerow([randomizedlist[i], fake.name(), fake.date_between_dates(mindate, maxdate), fake.street_address(), fake.state(), fake.city(), fake.zipcode()])
            i += 1  # Increment i

    print("CSV creation complete!\n")

create_csv()
    