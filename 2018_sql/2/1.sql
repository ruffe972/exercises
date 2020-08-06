use ershov_island

select surname,
       name,
       address,
       date_n_p,
       date_k_p,
       area
from person join occupant on person.id_person = occupant.id_person
            join house on house.id_house = occupant.id_house