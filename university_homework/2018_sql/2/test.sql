use ershov

select book.name,
       book.release_date,
       book.cover,
	   author.name
from book join authorship on book.id = authorship.book_id
          join author on author.id = authorship.author_id