use ershov_island

go
create proc getMarginals as
	with marginal_ids as
		(select person.id_person
		 from person
		 except
		 	 select person.id_person
		 	 from person join occupant on person.id_person = occupant.id_person)
	select person.id_person,
		   name,
		   surname
	from person join marginal_ids on marginal_ids.id_person = person.id_person
go
