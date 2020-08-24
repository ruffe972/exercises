use ershov

select name as book_name,
	   (avg (cast (rating as float))) as avg_rating
from book join book_user_record on book.id = book_user_record.book_id
group by book.name