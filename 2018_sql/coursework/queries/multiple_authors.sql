use ershov;
with authors_count_ as
	(select book_id,
		count(*) authors_count
	from authorship
	group by book_id)
select book_name, authors_count
from authors_count_ join book on book.id = book_id
where authors_count > 1;