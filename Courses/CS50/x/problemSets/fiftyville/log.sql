-- Keep a log of any SQL queries you execute as you solve the mystery.

-- learn the overall structure of the database
.tables
.schema

-- noticed that the crime_scence_reports would be the best place to start
-- categorize the tables: 
-- 10 tables in total, 6 groups: crime, airport, bank, people, bakery, interview?
--     {crime_scene_reports}
--     {interviews} ???
--     {airports, flights, passengers}
--     {atm_transactions, bank_accounts}
--     {people, phone_calls}
--     {bakery_secruity_logs}

-- a quick look at the 'people' table
.schema people
-- there's name, phone_number, passport and license_plate that we might be able to link with the other clues by joining the tables

-- learned the 'crime table content'
-- since we know the crime took place in Humphrey Street
SELECT *
  FROM crim_scene_reports
 WHERE street = "Humphrey Street";
-- spotted the description about the missing duck at ID no. 295
-- date: 2021-07-28
-- time 10:15 am
-- 3 interviews, all mentioned the "bakery"

-- checked the 'interviews' table with the above information
SELECT *
  FROM interviews
 WHERE month = 7
   AND day = 28
   AND transcript LIKE '%bakery%';
-- id 161, Ruth: within 10 minutes of the theft, thief's car left the bakery's parking lot
-- id 162, Eugene: recognized the thief, ATM on 'Leggett Street', withdrawing money
-- id 163, Raymond: while leaving bakery, thief called someone and talked less than a minute, flight out of town tmr, asked to purchase tickets
-- id 193, Emma (bakery owner): saw someone talked on phone for half an hour who didn't buy anything - though why is the id so far away from the first 3, and the reports only remarks of 3 interviews not 4 ???

-- checking the 'bakery_security_log' table
.schema bakery_security_log
SELECT license_plate
  FROM bakery_security_logs
 WHERE month = 7
   AND day = 28
   AND hour = 10
   AND minute <= 25
   AND activity = "exit";

-- checking the 'atm_transaction' table at the Leggett Street
.schema atm_transaction
SELECT account_number
  FROM atm_transactions
 WHERE atm_location = "Leggett Street"
   AND month = 7
   AND day = 28;
   AND transaction_type = "withdraw";

-- checking phone calls and flights
-- it is unclear whether the duration is in seconds or minutes, but I would assume it is in second, therefore
SELECT caller, receiver
  FROM phone_calls
 WHERE month = 7
   AND day = 28
   AND duration < 60;

-- next up is the flights/airport schedule
.schema airports
.schema flights
SELECT *
  FROM flights
 WHERE month = 7
   AND day = 29;
-- there are 5 flights leaving from the id 8 airport
-- double-checking and it is Fiftyville
SELECT *
  FROM airports
 WHERE id = 8;
-- get flights id to join with passengers tables
SELECT id
  FROM flights
 WHERE month = 7
   AND day = 29;
-- get passport number from passenger
SELECT passport_number
  FROM passengers
 WHERE flight_id IN
       (SELECT id
          FROM flights
         WHERE month = 7
           AND day = 29);

-- take person_id from 'bank_accounts' table using account_number
SELECT person_id
  FROM bank_accounts
 WHERE account_number IN
       (SELECT account_number
          FROM atm_transactions
         WHERE atm_location = "Leggett Street"
           AND month = 7
           AND day = 28
           AND transaction_type = "withdraw");

------
-- Gotten clues: person_id, passport_number, license_plate, phone_number (caller, receiver)
-- last table to use 'people'
SELECT name, phone_number
  FROM people
 WHERE license_plate IN
	   (SELECT license_plate
		  FROM bakery_security_logs
		 WHERE month = 7
		   AND day = 28
		   AND hour = 10
		   AND minute <= 25
		   AND activity = "exit")
   AND phone_number IN
	   (SELECT caller
		  FROM phone_calls
		 WHERE month = 7
		   AND day = 28
		   AND duration < 60)
-- here the condition for the flight_id was missing "the earliest flights of the day"
   AND passport_number IN
	   (SELECT passport_number
		  FROM passengers
		 WHERE flight_id IN
			   (SELECT id
				  FROM flights
				 WHERE month = 7
				   AND day = 29))
   AND id IN
	   (SELECT person_id
		  FROM bank_accounts
		 WHERE account_number in
			   (SELECT account_number
				  FROM atm_transactions
				 WHERE atm_location = "Leggett Street"
				   AND month = 7
				   AND day = 28
				   AND transaction_type = "withdraw"));

-- now left with 2 entries
-- Diana	(770) 555-1861
-- Bruce	(367) 555-5533

-- !!! "earliest flight out of Fifteville"
SELECT * FROM flights WHERE month = 7 AND day = 29 ORDER BY hour, minute LIMIT 1;
-- AND passport_number IN
--	   (SELECT passport_number
--		  FROM passengers
--		 WHERE flight_id IN
--			   (SELECT id
--				  FROM flights
--				 WHERE month = 7
--				   AND day = 29
-- the added lines
--				 ORDER BY hour, minute
--				 LIMIT 1))

-- now only Bruce is left and should be the thief
-- usinb Bruce's phone to reverse lookup his partner-in-crime
SELECT name
  FROM people
 WHERE phone_number =
       (SELECT receiver
          FROM phone_calls
         WHERE caller = "(367) 555-5533"
           AND month = 7
           AND day = 28
           AND duration < 60);
-- gotten "Robin"
-- their destination !!! not the full_name...
SELECT city
  FROM airports
 WHERE id =
       (SELECT destination_airport_id
          FROM flights
         WHERE month = 7
           AND day = 29
         ORDER BY hour, minute
         LIMIT 1);
-- which returns "New York City"
