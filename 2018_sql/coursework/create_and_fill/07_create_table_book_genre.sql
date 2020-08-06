use ershov

create table book_genre(
	id int identity primary key not null,
	genre_id int foreign key references genre(id) not null,
	book_id int foreign key references book(id) not null,
	genre_weight int not null default 1
)