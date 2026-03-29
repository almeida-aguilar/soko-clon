---
title: SokoClon Blog
---

## About

{% for page in site.about %}

### [{{ page.title }}]({{ page.url | relative_url }})

{% endfor %}

## Posts

{% for post in site.posts %}

### [*{{ post.date | date: "%Y-%m-%d" }}* | {{ post.title }}]({{ post.url | relative_url }})

{% endfor %}

---

- **GitHub**: [github.com/almeida-aguilar](https://github.com/almeida-aguilar)
- **LinkedIn**: [linkedin.com/in/almeida-aguilar](https://linkedin.com/in/almeida-aguilar)
- **Contacto**: [almeida.aguilar.contact@gmail.com](mailto:almeida.aguilar.contact@gmail.com)
