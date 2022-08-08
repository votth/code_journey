SELECT DISTINCT people.name
  FROM stars
  JOIN people ON stars.person_id = people.id
 WHERE movie_id IN
	   (SELECT movie_id
		  FROM stars
		 WHERE person_id =
			   (SELECT id
				  FROM people
				 WHERE name = "Kevin Bacon"
				   AND birth = 1958))
   AND people.name IS NOT "Kevin Bacon";
