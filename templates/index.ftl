<#include "header.ftl">
	
	<#include "menu.ftl">

	<div class="page-header">
            <div class="row">
                <div class="col-xs-4 col-md-2"><img src="/blog/img/cafe-leopard-h150.png"></div>
                <div class="col-xs-12 col-md-8"><h1>Java dans le hard(ware)</h1></div>
            </div>
	</div>
	<#list posts as post>
  		<#if (post.status == "published")>
  			<a href="/blog${post.uri}"><h1>${post.title}</h1></a>
  			<p>${post.date?string("dd MMMM yyyy")}</p>
  			<p>${post.body}</p>
  		</#if>
  	</#list>
	
	<hr />
	
	<p>Older posts are available in the <a href="/blog/${config.archive_file}">archive</a>.</p>

<#include "footer.ftl">