use ershov

create table author(
	id int identity primary key not null,
	author_name nvarchar(255) not null,
	photo nvarchar(255) not null,
	bio nvarchar(1023) not null
)