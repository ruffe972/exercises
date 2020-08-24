use ershov_island

declare @request_n_p date = '01.01.2000';
declare @request_k_p date = '06.09.2011';
declare @request_address varchar(50) = 'Красная, 1';

select person.id_person,
       surname,
       name,
       occupant.date_n_p,
       occupant.date_k_p from person
join occupant on person.id_person = occupant.id_person
join house on occupant.id_house = house.id_house
where house.address = @request_address
	  and @request_k_p >= occupant.date_n_p
      and (occupant.date_k_p is null or @request_n_p <= occupant.date_k_p)