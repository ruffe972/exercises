use ershov;
with pictures as
	(select photo from author
	union
	select cover from book)
select photo image_name from pictures
where photo != '';