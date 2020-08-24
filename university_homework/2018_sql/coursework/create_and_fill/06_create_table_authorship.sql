use ershov

create table authorship(
	id int identity primary key not null,
	book_id int foreign key references book(id) not null,
	author_id int foreign key references author(id) not null
)