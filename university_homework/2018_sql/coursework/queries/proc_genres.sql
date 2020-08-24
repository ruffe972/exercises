use ershov;
go
create proc get_book_genres @book_id int as
	with genre_ids as
		(select genre_id, genre_weight from book_genre
		where book_id = @book_id)
	select genre_name from genre
	join genre_ids on genre.id = genre_ids.genre_id
	order by genre_weight desc;