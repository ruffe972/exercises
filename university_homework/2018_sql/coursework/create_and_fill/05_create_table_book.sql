use ershov

create table book(
	id int identity primary key not null,
	book_name nvarchar(511) not null,
	release_date date,
	cover nvarchar(255) not null,
	annotation nvarchar(1023) not null
)