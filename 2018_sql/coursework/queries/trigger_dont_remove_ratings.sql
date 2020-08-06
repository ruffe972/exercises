use ershov;
go
create trigger do_not_remove on site_user instead of delete as
	update book_user_record set comment = ''
	where site_user_id in (select id from deleted);
	update site_user set username = ''
	where id in (select id from deleted);