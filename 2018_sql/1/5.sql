use ershov_island

select distinct address
from craft join businessman on craft.id_craft = businessman.id_craft
           join person on businessman.id_person = person.id_person
           join occupant on person.id_person = occupant.id_person
           join house on occupant.id_house = house.id_house
where name_craft = 'сбивание кокосов'