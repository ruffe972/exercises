use ershov;
with ratings as
	(select book_id,
		(avg (cast (rating as float))) as avg_rating
	from book join book_user_record on book.id = book_id
	group by book_id)
select book_name, avg_rating
from ratings join book on book.id = book_id
where avg_rating > 0
order by avg_rating desc;