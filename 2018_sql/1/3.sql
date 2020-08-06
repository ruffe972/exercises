use ershov_island

-- для удобства
select person.id_person,
       name,
       surname,
       sex,
       businessman.workmen
from person join businessman on person.id_person = businessman.id_person

select count (distinct person.id_person) as male_businessmen_with_subordinates
from person join businessman on person.id_person = businessman.id_person
where person.sex = 1 and businessman.workmen > 0

select max (workmen) as 'max',
       min (workmen) as 'min',
       avg (cast (workmen as float)) as 'avg'
from businessman