use ershov_island

select surname,
       person.name,
       name_craft,
	   craft.description,
	   workmen
from person join businessman on person.id_person = businessman.id_person
            join craft on businessman.id_craft = craft.id_craft
where date_k_d is null