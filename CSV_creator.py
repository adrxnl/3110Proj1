from faker import Faker
import random
import datetime
import csv

fake = Faker()

def create_csv():
    with open('fakePersonData.csv', 'w', newline='') as file:
        writer = csv.writer(file)
        i = 1
        mindate = datetime.datetime(1990, 1, 1)
        maxdate = datetime.datetime(2018, 12, 30)
        while i <= 10000:
            if i%2 == 0:
                id = i
                writer.writerow([id, fake.name(), fake.date_between_dates(mindate, maxdate), fake.street_address(), fake.state(), fake.city(), fake.zipcode()])
            else:
                id = 20010 - i
                writer.writerow([id, fake.name(), fake.date_between_dates(mindate, maxdate), fake.street_address(), fake.state(), fake.city(), fake.zipcode()])

            i = i + 1
 
    print("CSV creation complete!\n")



    

create_csv()

    