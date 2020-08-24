use ershov_island

select *
from person join occupant on person.id_person = occupant.id_person
            join house on occupant.id_house = house.id_house;

with requested_houses as
     (select distinct house.id_house, house.area
      from person join occupant on person.id_person = occupant.id_person
                  join house on occupant.id_house = house.id_house
      where person.date_r >= '01.01.1900' and person.date_r < '01.01.2000')
select count (id_house) as amount,
       sum (area) as area_sum,
       avg (area) as average
from requested_houses      